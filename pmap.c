/*
 * pmap.c: implementation of something like Solaris' /usr/proc/bin/pmap
 * for linux
 *
 * Author: Andy Isaacson <adi@acm.org>
 * Fri Jun 18 1999
 *
 * Updated Mon Oct 25 1999
 *  - calculate total size of shared mappings
 *  - change output format to read "writable/private" rather than "writable"
 *
 * Updated Sun Jul  8 2001
 *  - enlarge fixed-size buffers to handle long filenames
 *  - update spacing constants
 *  Thanks to Thomas Dorner <dorner@claranet.de> for the bug report
 *
 * Justification:  the formatting available in /proc/<pid>/maps is less
 * than optimal.  It's hard to figure out the size of a mapping from
 * that information (unless you can do 8-digit hex arithmetic in your
 * head) and it's just generally not friendly.  Hence this utility.
 *
 * I hereby place this work in the public domain.
 *
 * Compile with something along the lines of
 * gcc -O pmap.c -o pmap
 */

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

void
die(char *fmt, ...)
{
    va_list a;
    va_start(a, fmt);
    vfprintf(stderr, fmt, a);
    va_end(a);
    exit(1);
}

void print_name_pid(pid_t pid)
{
    char name[PATH_MAX];
    int c, i = 0;
    FILE *f;

    sprintf(name, "/proc/%ld/cmdline", (long) pid);
    f = fopen(name, "r");
    if(!f) die("%s: %s\n", name, strerror(errno));
    while((c = getc(f)) != EOF && c != 0)
        name[i++] = c;
    name[i] = '\0';
    printf("%s(%ld)\n", name, (long)pid);
}

void print_maps(pid_t pid)
{
    char fname[PATH_MAX];
    unsigned long writable = 0, total = 0, shared = 0;
    FILE *f;

    sprintf(fname, "/proc/%ld/maps", (long)pid);
    f = fopen(fname, "r");

    if(!f)
        die("%s: %s\n", fname, strerror(errno));

    while(!feof(f)) {
        char buf[PATH_MAX+100], perm[5], dev[6], mapname[PATH_MAX];
        unsigned long begin, end, size, inode, foo;
        int n;

        if(fgets(buf, sizeof(buf), f) == 0)
            break;
        mapname[0] = '\0';
        sscanf(buf, "%lx-%lx %4s %lx %5s %ld %s", &begin, &end, perm,
                &foo, dev, &inode, mapname);
        size = end - begin;
        total += size;
        /* the permission string looks like "rwxp", where each character can
         * be either the letter, or a hyphen.  The final character is either
         * p for private or s for shared.  We want to add up private writable
         * mappings, to get a feel for how much private memory this process
         * is taking.
         *
         * Also, we add up the shared mappings, to see how much this process
         * is sharing with others.
         */
        if(perm[3] == 'p') {
            if(perm[1] == 'w')
                writable += size;
        } else if(perm[3] == 's')
            shared += size;
        else
            die("unable to parse permission string: '%s'\n", perm);
        n = printf("%08lx (%ld KB)", begin, (end - begin)/1024);
        n += printf("%*s %s (%s %ld) ", 22-n, "", perm, dev, inode);
        printf("%*s %s\n", 44-n, "", mapname);
    }
    printf("mapped:   %ld KB writable/private: %ld KB shared: %ld KB\n",
            total/1024, writable/1024, shared/1024);
}

pid_t parse_pid(char *p)
{
    while(!isdigit(*p) && *p)
        p++;
    return strtol(p, 0, 0);
}

int main(int argc, char **argv)
{
    int i;

    if(argc < 2)
        die("usage: %s [pid|/proc/pid] ...\n", argv[0]);

    for(i=1; argv[i]; i++) {
        char *ppid;
        pid_t pid;

        ppid = argv[i];
        pid = parse_pid(ppid);
        print_name_pid(pid);
        print_maps(pid);
    }
    return 0;
}


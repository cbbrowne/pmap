pmap
====

pmap.c: implementation of something like Solaris' /usr/proc/bin/pmap

Author: Andy Isaacson <adi@acm.org>

See also: [http://web.hexapodia.org/~adi/pmap.c]

Output looks like the following:
```
5345:   xterm -class UXTerm -title uxterm -u8 -geometry +1+1
0000000000400000    408K r-x--  /usr/bin/xterm
0000000000665000      4K r----  /usr/bin/xterm
0000000000666000     32K rw---  /usr/bin/xterm
000000000066e000     12K rw---    [ anon ]
0000000001052000   9012K rw---    [ anon ]
00007f1965c7f000     20K r-x--  /usr/lib/x86_64-linux-gnu/libXfixes.so.3.1.0
00007f1965c84000   2048K -----  /usr/lib/x86_64-linux-gnu/libXfixes.so.3.1.0
00007f1965e84000      4K rw---  /usr/lib/x86_64-linux-gnu/libXfixes.so.3.1.0
00007f1965e85000     36K r-x--  /usr/lib/x86_64-linux-gnu/libXcursor.so.1.0.2
00007f1965e8e000   2048K -----  /usr/lib/x86_64-linux-gnu/libXcursor.so.1.0.2
00007f196608e000      4K rw---  /usr/lib/x86_64-linux-gnu/libXcursor.so.1.0.2
00007f196608f000     16K r-x--  /lib/x86_64-linux-gnu/libuuid.so.1.3.0
00007f1966093000   2044K -----  /lib/x86_64-linux-gnu/libuuid.so.1.3.0
00007f1966292000      4K r----  /lib/x86_64-linux-gnu/libuuid.so.1.3.0
00007f1966293000      4K rw---  /lib/x86_64-linux-gnu/libuuid.so.1.3.0
00007f1966294000     20K r-x--  /usr/lib/x86_64-linux-gnu/libXdmcp.so.6.0.0
00007f1966299000   2044K -----  /usr/lib/x86_64-linux-gnu/libXdmcp.so.6.0.0
00007f1966498000      4K rw---  /usr/lib/x86_64-linux-gnu/libXdmcp.so.6.0.0
00007f1966499000      8K r-x--  /usr/lib/x86_64-linux-gnu/libXau.so.6.0.0
00007f196649b000   2048K -----  /usr/lib/x86_64-linux-gnu/libXau.so.6.0.0
00007f196669b000      4K rw---  /usr/lib/x86_64-linux-gnu/libXau.so.6.0.0
00007f196669c000     28K r-x--  /usr/lib/x86_64-linux-gnu/libSM.so.6.0.1
00007f19666a3000   2044K -----  /usr/lib/x86_64-linux-gnu/libSM.so.6.0.1
00007f19668a2000      4K rw---  /usr/lib/x86_64-linux-gnu/libSM.so.6.0.1
00007f19668a3000      8K r-x--  /lib/x86_64-linux-gnu/libdl-2.13.so
00007f19668a5000   2048K -----  /lib/x86_64-linux-gnu/libdl-2.13.so
00007f1966aa5000      4K r----  /lib/x86_64-linux-gnu/libdl-2.13.so
00007f1966aa6000      4K rw---  /lib/x86_64-linux-gnu/libdl-2.13.so
00007f1966aa7000    124K r-x--  /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0
00007f1966ac6000   2044K -----  /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0
00007f1966cc5000      4K r----  /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0
00007f1966cc6000      4K rw---  /usr/lib/x86_64-linux-gnu/libxcb.so.1.1.0
00007f1966cc7000    156K r-x--  /lib/x86_64-linux-gnu/libexpat.so.1.6.0
00007f1966cee000   2048K -----  /lib/x86_64-linux-gnu/libexpat.so.1.6.0
00007f1966eee000      8K r----  /lib/x86_64-linux-gnu/libexpat.so.1.6.0
00007f1966ef0000      4K rw---  /lib/x86_64-linux-gnu/libexpat.so.1.6.0
00007f1966ef1000     88K r-x--  /lib/x86_64-linux-gnu/libz.so.1.2.7
00007f1966f07000   2044K -----  /lib/x86_64-linux-gnu/libz.so.1.2.7
00007f1967106000      4K r----  /lib/x86_64-linux-gnu/libz.so.1.2.7
00007f1967107000      4K rw---  /lib/x86_64-linux-gnu/libz.so.1.2.7
00007f1967108000     64K r-x--  /usr/lib/x86_64-linux-gnu/libXpm.so.4.11.0
00007f1967118000   2048K -----  /usr/lib/x86_64-linux-gnu/libXpm.so.4.11.0
00007f1967318000      4K rw---  /usr/lib/x86_64-linux-gnu/libXpm.so.4.11.0
00007f1967319000     72K r-x--  /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0
00007f196732b000   2048K -----  /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0
00007f196752b000      4K rw---  /usr/lib/x86_64-linux-gnu/libXext.so.6.4.0
00007f196752c000     36K r-x--  /usr/lib/x86_64-linux-gnu/libXrender.so.1.3.0
00007f1967535000   2044K -----  /usr/lib/x86_64-linux-gnu/libXrender.so.1.3.0
00007f1967734000      4K rw---  /usr/lib/x86_64-linux-gnu/libXrender.so.1.3.0
00007f1967735000    612K r-x--  /usr/lib/x86_64-linux-gnu/libfreetype.so.6.8.1
00007f19677ce000   2044K -----  /usr/lib/x86_64-linux-gnu/libfreetype.so.6.8.1
00007f19679cd000     24K r----  /usr/lib/x86_64-linux-gnu/libfreetype.so.6.8.1
00007f19679d3000      4K rw---  /usr/lib/x86_64-linux-gnu/libfreetype.so.6.8.1
00007f19679d4000     92K r-x--  /usr/lib/x86_64-linux-gnu/libICE.so.6.3.0
00007f19679eb000   2044K -----  /usr/lib/x86_64-linux-gnu/libICE.so.6.3.0
00007f1967bea000      8K rw---  /usr/lib/x86_64-linux-gnu/libICE.so.6.3.0
00007f1967bec000     12K rw---    [ anon ]
00007f1967bef000    384K r-x--  /usr/lib/x86_64-linux-gnu/libXt.so.6.0.0
00007f1967c4f000   2048K -----  /usr/lib/x86_64-linux-gnu/libXt.so.6.0.0
00007f1967e4f000      4K r----  /usr/lib/x86_64-linux-gnu/libXt.so.6.0.0
00007f1967e50000     20K rw---  /usr/lib/x86_64-linux-gnu/libXt.so.6.0.0
00007f1967e55000      4K rw---    [ anon ]
00007f1967e56000     96K r-x--  /usr/lib/x86_64-linux-gnu/libXmu.so.6.2.0
00007f1967e6e000   2048K -----  /usr/lib/x86_64-linux-gnu/libXmu.so.6.2.0
00007f196806e000      8K rw---  /usr/lib/x86_64-linux-gnu/libXmu.so.6.2.0
00007f1968070000   1240K r-x--  /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0
00007f19681a6000   2048K -----  /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0
00007f19683a6000     24K rw---  /usr/lib/x86_64-linux-gnu/libX11.so.6.3.0
00007f19683ac000    212K r-x--  /usr/lib/x86_64-linux-gnu/libfontconfig.so.1.5.0
00007f19683e1000   2048K -----  /usr/lib/x86_64-linux-gnu/libfontconfig.so.1.5.0
00007f19685e1000      4K r----  /usr/lib/x86_64-linux-gnu/libfontconfig.so.1.5.0
00007f19685e2000      4K rw---  /usr/lib/x86_64-linux-gnu/libfontconfig.so.1.5.0
00007f19685e3000   1524K r-x--  /lib/x86_64-linux-gnu/libc-2.13.so
00007f1968760000   2048K -----  /lib/x86_64-linux-gnu/libc-2.13.so
00007f1968960000     16K r----  /lib/x86_64-linux-gnu/libc-2.13.so
00007f1968964000      4K rw---  /lib/x86_64-linux-gnu/libc-2.13.so
00007f1968965000     20K rw---    [ anon ]
00007f196896a000    148K r-x--  /lib/x86_64-linux-gnu/libtinfo.so.5.9
00007f196898f000   2044K -----  /lib/x86_64-linux-gnu/libtinfo.so.5.9
00007f1968b8e000     16K r----  /lib/x86_64-linux-gnu/libtinfo.so.5.9
00007f1968b92000      4K rw---  /lib/x86_64-linux-gnu/libtinfo.so.5.9
00007f1968b93000      4K r-x--  /usr/lib/libutempter.so.1.1.5
00007f1968b94000   2048K -----  /usr/lib/libutempter.so.1.1.5
00007f1968d94000      4K rw---  /usr/lib/libutempter.so.1.1.5
00007f1968d95000    412K r-x--  /usr/lib/x86_64-linux-gnu/libXaw7.so.7.0.0
00007f1968dfc000   2048K -----  /usr/lib/x86_64-linux-gnu/libXaw7.so.7.0.0
00007f1968ffc000     44K rw---  /usr/lib/x86_64-linux-gnu/libXaw7.so.7.0.0
00007f1969007000     80K r-x--  /usr/lib/x86_64-linux-gnu/libXft.so.2.3.1
00007f196901b000   2048K -----  /usr/lib/x86_64-linux-gnu/libXft.so.2.3.1
00007f196921b000      4K rw---  /usr/lib/x86_64-linux-gnu/libXft.so.2.3.1
00007f196921c000    128K r-x--  /lib/x86_64-linux-gnu/ld-2.13.so
00007f1969258000    212K r--s-  /var/cache/nscd/group
00007f196928d000   1500K r----  /usr/lib/locale/locale-archive
00007f1969404000     44K rw---    [ anon ]
00007f1969432000     28K r--s-  /usr/lib/x86_64-linux-gnu/gconv/gconv-modules.cache
00007f1969439000      8K rw---    [ anon ]
00007f196943b000      4K r----  /lib/x86_64-linux-gnu/ld-2.13.so
00007f196943c000      4K rw---  /lib/x86_64-linux-gnu/ld-2.13.so
00007f196943d000      4K rw---    [ anon ]
00007fffb8edf000    132K rw---    [ stack ]
00007fffb8fbe000      4K r-x--    [ anon ]
ffffffffff600000      4K r-x--    [ anon ]
 total            66440K
```

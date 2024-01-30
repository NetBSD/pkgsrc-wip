$NetBSD$

[ 83%] Building CXX object LaunchAPPL/Client/CMakeFiles/LaunchAPPL.dir/LaunchMethod.cc.o
In file included from /tmp/wip/Retro68/work/Retro68-2019.8.2/PEFTools/../gcc/newlib/libc/include/_ansi.h:11,
                 from /tmp/wip/Retro68/work/Retro68-2019.8.2/PEFTools/../gcc/newlib/libc/include/alloca.h:10,
                 from /tmp/wip/Retro68/work/Retro68-2019.8.2/PEFTools/MakePEF.cc:9:
/tmp/wip/Retro68/work/Retro68-2019.8.2/PEFTools/../gcc/newlib/libc/include/sys/config.h:5:10: fatal error: sys/features.h: No such file or directory
    5 | #include <sys/features.h> /* POSIX defs */
      |          ^~~~~~~~~~~~~~~~
compilation terminated.

--- PEFTools/../gcc/newlib/libc/include/sys/config.h.orig	2024-01-30 22:57:05.167249422 +0900
+++ PEFTools/../gcc/newlib/libc/include/sys/config.h	2024-01-30 22:58:26.400601194 +0900
@@ -2,7 +2,7 @@
 #define __SYS_CONFIG_H__
 
 #include <machine/ieeefp.h>  /* floating point macros */
-#include <sys/features.h>	/* POSIX defs */
+#include "features.h"	/* POSIX defs */
 
 #ifdef __aarch64__
 #define MALLOC_ALIGNMENT 16

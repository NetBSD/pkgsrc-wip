$NetBSD$

[ 87%] Building CXX object Elf2Mac/CMakeFiles/Elf2Mac.dir/Symbol.cc.o
In file included from /tmp/wip/retro68/work/Retro68-2019.8.2/PEFTools/../gcc/newlib/libc/include/sys/config.h:5,
                 from /tmp/wip/retro68/work/Retro68-2019.8.2/PEFTools/../gcc/newlib/libc/include/_ansi.h:11,
                 from /tmp/wip/retro68/work/Retro68-2019.8.2/PEFTools/../gcc/newlib/libc/include/alloca.h:10,
                 from /tmp/wip/retro68/work/Retro68-2019.8.2/PEFTools/MakePEF.cc:9:
/tmp/wip/retro68/work/Retro68-2019.8.2/PEFTools/../gcc/newlib/libc/include/sys/features.h:28:10: fatal error: _newlib_version.h: No such file or directory
   28 | #include "_newlib_version.h"
      |          ^~~~~~~~~~~~~~~~~~~
compilation terminated.

--- PEFTools/../gcc/newlib/libc/include/sys/features.h.orig	2019-08-24 19:56:10.000000000 +0900
+++ PEFTools/../gcc/newlib/libc/include/sys/features.h	2024-01-31 00:27:35.504855452 +0900
@@ -25,7 +25,7 @@
 extern "C" {
 #endif
 
-#include <_newlib_version.h>
+#include "../_newlib_version.h"
 
 /* Macro to test version of GCC.  Returns 0 for non-GCC or too old GCC. */
 #ifndef __GNUC_PREREQ

$NetBSD$

[ 83%] Building CXX object LaunchAPPL/Client/CMakeFiles/LaunchAPPL.dir/LaunchMethod.cc.o
/tmp/wip/Retro68/work/Retro68-2019.8.2/PEFTools/MakePEF.cc:8:10: fatal error: alloca.h: No such file or directory
    8 | #include <alloca.h>
      |          ^~~~~~~~~~
compilation terminated.

--- PEFTools/MakePEF.cc.orig	2019-08-24 19:56:10.000000000 +0900
+++ PEFTools/MakePEF.cc	2024-01-30 22:19:27.932859420 +0900
@@ -5,7 +5,8 @@
 #include <fstream>
 #include <set>
 #include <string.h>
-#include <alloca.h>
+/* #include <alloca.h> */
+#include "../gcc/newlib/libc/include/alloca.h"
 
 #include <assert.h>
 #include <stdint.h>

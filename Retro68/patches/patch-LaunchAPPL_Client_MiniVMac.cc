$NetBSD$
:
[ 89%] Building CXX object LaunchAPPL/Client/CMakeFiles/LaunchAPPL.dir/SSH.cc.o
/tmp/wip/Retro68/work/Retro68-2019.8.2/LaunchAPPL/Client/MiniVMac.cc:8:10: fatal error: hfs.h: No such file or directory
    8 | #include "hfs.h"
      |          ^~~~~~~
compilation terminated.

--- LaunchAPPL/Client/MiniVMac.cc.orig	2019-08-24 19:56:10.000000000 +0900
+++ LaunchAPPL/Client/MiniVMac.cc	2024-01-30 22:46:31.665649819 +0900
@@ -5,7 +5,8 @@
 #include "ResourceFile.h"
 
 extern "C" {
-#include "hfs.h"
+/* #include "hfs.h" */
+#include "../../hfsutils/libhfs/hfs.h"
 }
 
 #include <iostream>

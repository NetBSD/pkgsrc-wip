$NetBSD$

/tmp/wip/Retro68/work/Retro68-2019.8.2/ResourceFiles/ResourceFile.cc:13:10: fatal error: hfs.h: No such file or directory
   13 | #include "hfs.h"
      |          ^~~~~~~
compilation terminated.

--- ResourceFiles/ResourceFile.cc.orig	2019-08-24 19:56:10.000000000 +0900
+++ ResourceFiles/ResourceFile.cc	2024-01-30 22:13:51.335496105 +0900
@@ -10,7 +10,7 @@
 #include <sys/xattr.h>
 #endif
 extern "C" {
-#include "hfs.h"
+#include "libhfs/hfs.h"
 }
 
 namespace fs = boost::filesystem;

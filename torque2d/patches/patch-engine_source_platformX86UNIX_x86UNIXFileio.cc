$NetBSD$

--- engine/source/platformX86UNIX/x86UNIXFileio.cc.orig	2016-04-04 01:25:01.000000000 +0000
+++ engine/source/platformX86UNIX/x86UNIXFileio.cc
@@ -57,7 +57,7 @@
  #include "io/resource/resourceManager.h"
  #include "game/gameInterface.h" 
 
- #if defined(__FreeBSD__)
+ #if defined(__FreeBSD__) || defined(__NetBSD__)
     #include <sys/types.h>
  #endif
  #include <utime.h>

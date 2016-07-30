$NetBSD$

--- Engine/source/platformX86UNIX/x86UNIXFileio.cpp.orig	2016-07-12 13:56:01.000000000 +0000
+++ Engine/source/platformX86UNIX/x86UNIXFileio.cpp
@@ -58,7 +58,7 @@
  #include "cinterface/cinterface.h"
  #include "core/volume.h"
 
- #if defined(__FreeBSD__)
+ #if defined(__FreeBSD__) || defined(__NetBSD__)
     #include <sys/types.h>
  #endif
  #include <utime.h>

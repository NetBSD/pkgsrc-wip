$NetBSD$

Add NetBSD compilation fix.
TODO: add proper support.

--- CPP/Windows/System.cpp.orig	2023-06-18 13:11:43.000000000 +0000
+++ CPP/Windows/System.cpp
@@ -7,9 +7,11 @@
 #ifdef __APPLE__
 #include <sys/sysctl.h>
 #else
+#ifndef __NetBSD__
 #include <sys/sysinfo.h>
 #endif
 #endif
+#endif
 
 #include "../Common/Defs.h"
 // #include "../Common/MyWindows.h"
@@ -203,6 +205,8 @@ bool GetRamSize(UInt64 &size)
 
   #elif defined(_AIX)
   // fixme
+  #elif defined(__NetBSD__)
+  // fixme
   #elif defined(__gnu_hurd__)
   // fixme
   #elif defined(__FreeBSD_kernel__) && defined(__GLIBC__)

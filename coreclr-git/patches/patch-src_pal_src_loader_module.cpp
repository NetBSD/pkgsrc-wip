$NetBSD$

--- src/pal/src/loader/module.cpp.orig	2016-02-06 02:05:27.000000000 +0000
+++ src/pal/src/loader/module.cpp
@@ -44,9 +44,7 @@ Abstract:
 #else   // NEED_DLCOMPAT
 #include <dlfcn.h>
 #endif  // NEED_DLCOMPAT
-#if HAVE_ALLOCA_H
-#include <alloca.h>
-#endif  // HAVE_ALLOCA_H
+#include <stdlib.h>
 
 #ifdef __APPLE__
 #include <mach-o/dyld.h>

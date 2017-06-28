$NetBSD$

--- lib/interception/interception_linux.cc.orig	2017-06-03 23:53:56.000000000 +0000
+++ lib/interception/interception_linux.cc
@@ -12,7 +12,7 @@
 // Linux-specific interception methods.
 //===----------------------------------------------------------------------===//
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include "interception.h"
 
 #include <dlfcn.h>   // for dlsym() and dlvsym()
@@ -33,4 +33,4 @@ void *GetFuncAddrVer(const char *func_na
 }  // namespace __interception
 
 
-#endif  // __linux__ || __FreeBSD__
+#endif  // __linux__ || __FreeBSD__ || __NetBSD__

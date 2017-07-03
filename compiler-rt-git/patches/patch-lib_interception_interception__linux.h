$NetBSD$

--- lib/interception/interception_linux.h.orig	2017-07-03 15:33:06.000000000 +0000
+++ lib/interception/interception_linux.h
@@ -12,7 +12,7 @@
 // Linux-specific interception methods.
 //===----------------------------------------------------------------------===//
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) | defined(__NetBSD__)
 
 #if !defined(INCLUDED_FROM_INTERCEPTION_LIB)
 # error "interception_linux.h should be included from interception library only"
@@ -44,4 +44,4 @@ void *GetFuncAddrVer(const char *func_na
 #endif  // !defined(__ANDROID__)
 
 #endif  // INTERCEPTION_LINUX_H
-#endif  // __linux__ || __FreeBSD__
+#endif  // __linux__ || __FreeBSD__ || __NetBSD__

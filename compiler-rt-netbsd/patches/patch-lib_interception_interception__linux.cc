$NetBSD$

--- lib/interception/interception_linux.cc.orig	2017-06-03 23:53:56.000000000 +0000
+++ lib/interception/interception_linux.cc
@@ -12,14 +12,28 @@
 // Linux-specific interception methods.
 //===----------------------------------------------------------------------===//
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include "interception.h"
 
 #include <dlfcn.h>   // for dlsym() and dlvsym()
 
+#ifdef __NetBSD__
+static int mystrcmp(const char *s1, const char *s2) {
+  while (*s1 == *s2++)
+    if (*s1++ == 0)
+      return (0);
+  return (*(const unsigned char *)s1 - *(const unsigned char *)--s2);
+}
+#endif
+
 namespace __interception {
 bool GetRealFunctionAddress(const char *func_name, uptr *func_addr,
     uptr real, uptr wrapper) {
+#ifdef __NetBSD__
+  // XXX: Until I come up with something better to deal with renames.
+  if (mystrcmp(func_name, "sigaction") == 0)
+    func_name = "__sigaction14";
+#endif
   *func_addr = (uptr)dlsym(RTLD_NEXT, func_name);
   return real == wrapper;
 }
@@ -33,4 +47,4 @@ void *GetFuncAddrVer(const char *func_na
 }  // namespace __interception
 
 
-#endif  // __linux__ || __FreeBSD__
+#endif  // __linux__ || __FreeBSD__ || __NetBSD__

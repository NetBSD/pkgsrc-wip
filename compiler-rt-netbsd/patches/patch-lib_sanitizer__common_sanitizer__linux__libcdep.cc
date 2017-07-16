$NetBSD$

--- lib/sanitizer_common/sanitizer_linux_libcdep.cc.orig	2017-07-16 22:40:10.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cc
@@ -14,7 +14,7 @@
 
 #include "sanitizer_platform.h"
 
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 
 #include "sanitizer_allocator_internal.h"
 #include "sanitizer_atomic.h"
@@ -148,7 +148,8 @@ bool SanitizerGetThreadName(char *name, 
 #endif
 }
 
-#if !SANITIZER_FREEBSD && !SANITIZER_ANDROID && !SANITIZER_GO
+#if !SANITIZER_FREEBSD && !SANITIZER_ANDROID && !SANITIZER_GO && \
+    !SANITIZER_NETBSD
 static uptr g_tls_size;
 
 #ifdef __i386__
@@ -176,7 +177,8 @@ void InitTlsSize() {
 }
 #else
 void InitTlsSize() { }
-#endif  // !SANITIZER_FREEBSD && !SANITIZER_ANDROID && !SANITIZER_GO
+#endif  // !SANITIZER_FREEBSD && !SANITIZER_ANDROID && !SANITIZER_GO &&
+        // !SANITIZER_NETBSD
 
 #if (defined(__x86_64__) || defined(__i386__) || defined(__mips__) \
     || defined(__aarch64__) || defined(__powerpc64__) || defined(__s390__) \
@@ -333,6 +335,10 @@ uptr ThreadSelf() {
 }
 #endif  // SANITIZER_FREEBSD
 
+#if SANITIZER_NETBSD
+uptr ThreadSelf() { return (uptr)pthread_self(); }
+#endif  // SANITIZER_NETBSD
+
 #if !SANITIZER_GO
 static void GetTls(uptr *addr, uptr *size) {
 #if SANITIZER_LINUX && !SANITIZER_ANDROID
@@ -362,7 +368,7 @@ static void GetTls(uptr *addr, uptr *siz
     *addr = (uptr) dtv[2];
     *size = (*addr == 0) ? 0 : ((uptr) segbase[0] - (uptr) dtv[2]);
   }
-#elif SANITIZER_ANDROID
+#elif SANITIZER_ANDROID || SANITIZER_NETBSD
   *addr = 0;
   *size = 0;
 #else
@@ -373,7 +379,7 @@ static void GetTls(uptr *addr, uptr *siz
 
 #if !SANITIZER_GO
 uptr GetTlsSize() {
-#if SANITIZER_FREEBSD || SANITIZER_ANDROID
+#if SANITIZER_FREEBSD || SANITIZER_ANDROID || SANITIZER_NETBSD
   uptr addr, size;
   GetTls(&addr, &size);
   return size;

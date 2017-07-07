$NetBSD$

--- lib/sanitizer_common/sanitizer_linux_libcdep.cc.orig	2017-07-03 15:33:06.000000000 +0000
+++ lib/sanitizer_common/sanitizer_linux_libcdep.cc
@@ -14,7 +14,7 @@
 
 #include "sanitizer_platform.h"
 
-#if SANITIZER_FREEBSD || SANITIZER_LINUX
+#if SANITIZER_FREEBSD || SANITIZER_LINUX || SANITIZER_NETBSD
 
 #include "sanitizer_allocator_internal.h"
 #include "sanitizer_atomic.h"
@@ -22,6 +22,7 @@
 #include "sanitizer_flags.h"
 #include "sanitizer_freebsd.h"
 #include "sanitizer_linux.h"
+#include "sanitizer_netbsd.h"
 #include "sanitizer_placement_new.h"
 #include "sanitizer_procmaps.h"
 #include "sanitizer_stacktrace.h"
@@ -151,7 +152,8 @@ bool SanitizerGetThreadName(char *name, 
 #endif
 }
 
-#if !SANITIZER_FREEBSD && !SANITIZER_ANDROID && !SANITIZER_GO
+#if !SANITIZER_FREEBSD && !SANITIZER_ANDROID && !SANITIZER_GO && \
+    !SANITIZER_NETBSD
 static uptr g_tls_size;
 
 #ifdef __i386__
@@ -179,7 +181,8 @@ void InitTlsSize() {
 }
 #else
 void InitTlsSize() { }
-#endif  // !SANITIZER_FREEBSD && !SANITIZER_ANDROID && !SANITIZER_GO
+#endif  // !SANITIZER_FREEBSD && !SANITIZER_ANDROID && !SANITIZER_GO &&
+        // !SANITIZER_NETBSD
 
 #if (defined(__x86_64__) || defined(__i386__) || defined(__mips__) \
     || defined(__aarch64__) || defined(__powerpc64__) || defined(__s390__) \
@@ -336,6 +339,10 @@ uptr ThreadSelf() {
 }
 #endif  // SANITIZER_FREEBSD
 
+#if SANITIZER_NETBSD
+uptr ThreadSelf() { return (uptr)pthread_self(); }
+#endif  // SANITIZER_NETBSD
+
 #if !SANITIZER_GO
 static void GetTls(uptr *addr, uptr *size) {
 #if SANITIZER_LINUX && !SANITIZER_ANDROID
@@ -365,7 +372,7 @@ static void GetTls(uptr *addr, uptr *siz
     *addr = (uptr) dtv[2];
     *size = (*addr == 0) ? 0 : ((uptr) segbase[0] - (uptr) dtv[2]);
   }
-#elif SANITIZER_ANDROID
+#elif SANITIZER_ANDROID || SANITIZER_NETBSD
   *addr = 0;
   *size = 0;
 #else
@@ -376,7 +383,7 @@ static void GetTls(uptr *addr, uptr *siz
 
 #if !SANITIZER_GO
 uptr GetTlsSize() {
-#if SANITIZER_FREEBSD || SANITIZER_ANDROID
+#if SANITIZER_FREEBSD || SANITIZER_ANDROID || SANITIZER_NETBSD
   uptr addr, size;
   GetTls(&addr, &size);
   return size;

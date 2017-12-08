$NetBSD$

--- lib/sanitizer_common/sanitizer_common_interceptors.inc.orig	2017-12-04 19:21:19.000000000 +0000
+++ lib/sanitizer_common/sanitizer_common_interceptors.inc
@@ -3413,7 +3413,7 @@ INTERCEPTOR(char *, strerror, int errnum
 //  * GNU version returns message pointer, which points to either buf or some
 //    static storage.
 #if ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !_GNU_SOURCE) || \
-    SANITIZER_MAC || SANITIZER_ANDROID
+    SANITIZER_MAC || SANITIZER_ANDROID || SANITIZER_NETBSD
 // POSIX version. Spec is not clear on whether buf is NULL-terminated.
 // At least on OSX, buf contents are valid even when the call fails.
 INTERCEPTOR(int, strerror_r, int errnum, char *buf, SIZE_T buflen) {

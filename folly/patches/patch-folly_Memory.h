$NetBSD$

NetBSD support.

--- folly/Memory.h.orig	2024-08-17 18:59:35.000000000 +0000
+++ folly/Memory.h
@@ -45,7 +45,8 @@ namespace folly {
 #if (defined(_POSIX_C_SOURCE) && _POSIX_C_SOURCE >= 200112L) || \
     (defined(_XOPEN_SOURCE) && _XOPEN_SOURCE >= 600) ||         \
     (defined(__ANDROID__) && (__ANDROID_API__ > 16)) ||         \
-    (defined(__APPLE__)) || defined(__FreeBSD__) || defined(__wasm32__)
+    (defined(__APPLE__)) || defined(__FreeBSD__) || 		\
+    defined(__NetBSD__) || defined(__wasm32__)
 
 inline void* aligned_malloc(size_t size, size_t align) {
   // use posix_memalign, but mimic the behaviour of memalign

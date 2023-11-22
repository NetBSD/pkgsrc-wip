$NetBSD$

Use posix_memalign on NetBSD too.

--- folly/Memory.h.orig	2023-11-19 20:05:55.000000000 +0000
+++ folly/Memory.h
@@ -48,7 +48,7 @@ namespace folly {
     (defined(__APPLE__) &&                                      \
      (__MAC_OS_X_VERSION_MIN_REQUIRED >= __MAC_10_6 ||          \
       __IPHONE_OS_VERSION_MIN_REQUIRED >= __IPHONE_3_0)) ||     \
-    defined(__FreeBSD__) || defined(__wasm32__)
+    defined(__FreeBSD__) || defined(__NetBSD__) || defined(__wasm32__)
 
 inline void* aligned_malloc(size_t size, size_t align) {
   // use posix_memalign, but mimic the behaviour of memalign

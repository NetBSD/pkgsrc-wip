$NetBSD$

Fix build on non-GLIBC.
https://boringssl.googlesource.com/boringssl/+/66d8563227085a59bbe44ef32068aaec87cc8f6c%5E%21/

--- ../vendor/boringssl-src-0.3.0+688fc5c/boringssl/src/include/openssl/thread.h.orig	1970-01-01 00:00:00.000000000 +0000
+++ ../vendor/boringssl-src-0.3.0+688fc5c/boringssl/src/include/openssl/thread.h
@@ -77,7 +77,7 @@ typedef struct crypto_mutex_st {
 typedef union crypto_mutex_st {
   void *handle;
 } CRYPTO_MUTEX;
-#elif defined(__MACH__) && defined(__APPLE__)
+#elif !defined(__GLIBC__)
 typedef pthread_rwlock_t CRYPTO_MUTEX;
 #else
 // It is reasonable to include pthread.h on non-Windows systems, however the

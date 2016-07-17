$NetBSD$

--- third_party/boringssl/src/include/openssl/thread.h.orig	2016-06-24 01:03:31.000000000 +0000
+++ third_party/boringssl/src/include/openssl/thread.h
@@ -87,6 +87,9 @@ typedef pthread_rwlock_t CRYPTO_MUTEX;
 typedef union crypto_mutex_st {
   double alignment;
   uint8_t padding[3*sizeof(int) + 5*sizeof(unsigned) + 16 + 8];
+#if defined(__NetBSD__)
+  uint8_t      nbpad[64 + 8];
+#endif
 } CRYPTO_MUTEX;
 #endif
 

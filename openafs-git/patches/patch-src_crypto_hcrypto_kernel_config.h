$NetBSD$

--- src/crypto/hcrypto/kernel/config.h.orig	2018-05-07 18:33:23.000000000 +0000
+++ src/crypto/hcrypto/kernel/config.h
@@ -60,15 +60,19 @@
 #define calloc _afscrypto_calloc
 void * _afscrypto_calloc(int, size_t);
 
+#undef malloc
 #define malloc _afscrypto_malloc
 void * _afscrypto_malloc(size_t);
 
+#undef free
 #define free _afscrypto_free
 void _afscrypto_free(void *);
 
+#undef strdup
 #define strdup _afscrypto_strdup
 char * _afscrypto_strdup(const char *);
 
+#undef realloc
 #define realloc _afscrypto_realloc
 void * _afscrypto_realloc(void *, size_t);
 

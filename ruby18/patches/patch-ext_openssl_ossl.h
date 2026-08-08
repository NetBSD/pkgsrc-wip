$NetBSD$

--- ext/openssl/ossl.h.orig	2010-06-21 09:18:59.000000000 +0000
+++ ext/openssl/ossl.h
@@ -114,10 +114,19 @@ extern VALUE eOSSLError;
 #define STACK _STACK
 #endif
 
+#if 0
 /*
+ * Compatibility
+ */
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#define STACK _STACK
+#endif
+#endif
+
+/*
  * String to HEXString conversion
  */
-int string2hex(char *, int, char **, int *);
+int string2hex(const unsigned char *, int, char **, int *);
 
 /*
  * Data Conversion

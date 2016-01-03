$NetBSD$

--- src/X509Certificate.cpp.orig	2016-01-03 16:55:29.000000000 +0000
+++ src/X509Certificate.cpp
@@ -279,7 +279,11 @@ int X509Certificate::getBasicConstraints
     }
     X509_EXTENSION *ext = NULL;
     int pathlen = -1;
+#if (OPENSSL_VERSION_NUMBER >= 0x10000000L)
+    const X509V3_EXT_METHOD *method = NULL;
+#else
     X509V3_EXT_METHOD *method = NULL;
+#endif
     STACK_OF(CONF_VALUE) *vals = NULL;
     void *ext_str = NULL;
 

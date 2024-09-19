$NetBSD$

--- src/TrustVerifier.cpp.orig	2016-01-03 17:42:47.000000000 +0000
+++ src/TrustVerifier.cpp
@@ -123,7 +123,11 @@ int X509TrustVerifier::verifyTrust (vect
     {
         THROW(LibError, "Failed to retrieve keystore data", -1);
     }
+#if (OPENSSL_VERSION_NUMBER >= 0x10000000L)
+    STACK_OF(X509_CRL)* crl = sk_X509_CRL_new_null();
+#else
     STACK_OF(X509)* crl = sk_X509_new_null();
+#endif
     STACK_OF(X509)* stack = sk_X509_new_null();
     if (!stack)
     {

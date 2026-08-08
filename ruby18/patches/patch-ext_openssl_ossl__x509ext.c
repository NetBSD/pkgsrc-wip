$NetBSD$

--- ext/openssl/ossl_x509ext.c.orig	2010-05-24 23:58:49.000000000 +0000
+++ ext/openssl/ossl_x509ext.c
@@ -274,7 +274,7 @@ ossl_x509ext_initialize(int argc, VALUE *argv, VALUE s
 ossl_x509ext_initialize(int argc, VALUE *argv, VALUE self)
 {
     VALUE oid, value, critical;
-    unsigned char *p;
+    const unsigned char *p;
     X509_EXTENSION *ext;
 
     GetX509Ext(self, ext);

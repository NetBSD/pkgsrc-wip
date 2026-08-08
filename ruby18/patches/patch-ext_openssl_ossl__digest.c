$NetBSD$

--- ext/openssl/ossl_digest.c.orig	2012-06-18 09:53:29.000000000 +0000
+++ ext/openssl/ossl_digest.c
@@ -38,7 +38,7 @@ GetDigestPtr(VALUE obj)
     const EVP_MD *md;
 
     if (TYPE(obj) == T_STRING) {
-    	const char *name = STR2CSTR(obj);
+    	const char *name = StringValueCStr(obj);
 
         md = EVP_get_digestbyname(name);
         if (!md)
@@ -98,7 +98,6 @@ ossl_digest_initialize(int argc, VALUE *argv, VALUE se
 {
     EVP_MD_CTX *ctx;
     const EVP_MD *md;
-    char *name;
     VALUE type, data;
 
     rb_scan_args(argc, argv, "11", &type, &data);
@@ -188,7 +187,7 @@ ossl_digest_finish(int argc, VALUE *argv, VALUE self)
         rb_str_resize(str, EVP_MD_CTX_size(ctx));
     }
 
-    EVP_DigestFinal_ex(ctx, RSTRING_PTR(str), NULL);
+    EVP_DigestFinal_ex(ctx, (unsigned char *)RSTRING_PTR(str), NULL);
 
     return str;
 }
@@ -240,7 +239,6 @@ Init_ossl_digest()
 void
 Init_ossl_digest()
 {
-    rb_require("openssl");
     rb_require("digest");
 
 #if 0 /* let rdoc know about mOSSL */

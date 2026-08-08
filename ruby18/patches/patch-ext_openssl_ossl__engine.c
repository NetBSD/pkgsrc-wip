$NetBSD$

--- ext/openssl/ossl_engine.c.orig	2010-06-21 09:18:59.000000000 +0000
+++ ext/openssl/ossl_engine.c
@@ -344,7 +344,7 @@ ossl_engine_inspect(VALUE self)
 ossl_engine_inspect(VALUE self)
 {
     VALUE str;
-    char *cname = rb_class2name(rb_obj_class(self));
+    const char *cname = rb_class2name(rb_obj_class(self));
     
     str = rb_str_new2("#<");
     rb_str_cat2(str, cname);

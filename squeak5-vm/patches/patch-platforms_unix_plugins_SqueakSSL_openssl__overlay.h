$NetBSD$

--- platforms/unix/plugins/SqueakSSL/openssl_overlay.h.orig	2022-06-02 14:10:44.000000000 +0000
+++ platforms/unix/plugins/SqueakSSL/openssl_overlay.h
@@ -524,6 +524,7 @@ static size_t _sqo_lib_paths(size_t cons
     _SQO_ADD_LIB("/lib");
     _SQO_ADD_LIB("/usr/lib");
     _SQO_ADD_LIB("/usr/local/lib");
+    _SQO_ADD_LIB("@pkglibdir@");
 #if INTPTR_MAX == INT32_MAX
     _SQO_ADD_LIB("/lib32");
     _SQO_ADD_LIB("/usr/lib32");

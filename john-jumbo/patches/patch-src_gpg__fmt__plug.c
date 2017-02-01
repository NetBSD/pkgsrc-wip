$NetBSD$

--- src/gpg_fmt_plug.c.orig	2014-12-18 07:59:02.000000000 +0000
+++ src/gpg_fmt_plug.c
@@ -27,6 +27,7 @@ john_register_one(&fmt_gpg);
 #else
 
 #include <string.h>
+#include <des.h>
 #include <openssl/aes.h>
 #include <assert.h>
 #include <openssl/blowfish.h>

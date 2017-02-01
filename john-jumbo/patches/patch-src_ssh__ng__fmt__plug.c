$NetBSD$

--- src/ssh_ng_fmt_plug.c.orig	2014-12-18 07:59:02.000000000 +0000
+++ src/ssh_ng_fmt_plug.c
@@ -20,6 +20,7 @@ john_register_one(&fmt_sshng);
 #else
 
 #include <string.h>
+#include <des.h>
 #include <openssl/aes.h>
 #include <openssl/des.h>
 #include <openssl/asn1.h>

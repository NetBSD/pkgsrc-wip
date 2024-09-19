$NetBSD$

--- src/X509Certificate.h.orig	2016-01-03 16:55:29.000000000 +0000
+++ src/X509Certificate.h
@@ -18,6 +18,7 @@
 #define _X509CERTIFICATE_H
 
 #include <string>
+#include <strings.h>
 #include <openssl/x509.h>
 
 class X509Certificate;

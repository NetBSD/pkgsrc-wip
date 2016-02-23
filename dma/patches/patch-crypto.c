$NetBSD$

Include strings.h for bzero and bcopy function.

--- crypto.c.orig	2016-02-07 12:41:49.000000000 +0000
+++ crypto.c
@@ -40,6 +40,7 @@
 #include <openssl/pem.h>
 #include <openssl/rand.h>
 
+#include <strings.h>
 #include <syslog.h>
 
 #include "dma.h"

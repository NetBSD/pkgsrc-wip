$NetBSD$

Fix warning about implicite declaration

--- libfreefare/mifare_desfire_crypto.c.orig	2022-05-13 14:33:06.661095334 +0000
+++ libfreefare/mifare_desfire_crypto.c
@@ -60,6 +60,8 @@
 #include <string.h>
 #include <strings.h>
 
+#include <stdlib.h>
+
 #ifdef WITH_DEBUG
 #  include <libutil.h>
 #endif

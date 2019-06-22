$NetBSD$

Use libilbc. Almost no changes.

--- modules/ilbc/ilbc.c.orig	2019-06-22 07:51:28.000000000 +0000
+++ modules/ilbc/ilbc.c
@@ -6,9 +6,13 @@
 #include <re.h>
 #include <rem.h>
 #include <baresip.h>
-#include <iLBC_define.h>
-#include <iLBC_decode.h>
-#include <iLBC_encode.h>
+#include <ilbc.h>
+#include <string.h>
+
+#define NO_OF_BYTES_20MS	38
+#define NO_OF_BYTES_30MS	50
+#define NO_OF_WORDS_20MS	19
+#define NO_OF_WORDS_30MS	25
 
 
 /**

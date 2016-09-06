$NetBSD$

Use libilbc. Almost no changes.

--- modules/ilbc/ilbc.c.orig	2016-07-22 19:17:45.000000000 +0000
+++ modules/ilbc/ilbc.c
@@ -5,10 +5,13 @@
  */
 #include <re.h>
 #include <baresip.h>
-#include <iLBC_define.h>
-#include <iLBC_decode.h>
-#include <iLBC_encode.h>
+#include <ilbc.h>
+#include <string.h>
 
+#define NO_OF_BYTES_20MS	38
+#define NO_OF_BYTES_30MS	50
+#define NO_OF_WORDS_20MS	19
+#define NO_OF_WORDS_30MS	25
 
 /**
  * @defgroup ilbc ilbc

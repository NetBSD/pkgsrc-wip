$NetBSD$

--- src/mod/codecs/mod_codec2/mod_codec2.c.orig	2016-01-11 23:51:12.000000000 +0000
+++ src/mod/codecs/mod_codec2/mod_codec2.c
@@ -29,7 +29,7 @@
  */
 
 #include <switch.h>
-#include <codec2.h>
+#include <codec2/codec2.h>
 
 /* Uncomment to log input/output data for debugging 
 #define LOG_DATA 

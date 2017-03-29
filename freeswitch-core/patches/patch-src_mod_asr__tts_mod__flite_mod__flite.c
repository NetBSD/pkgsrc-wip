$NetBSD$

--- src/mod/asr_tts/mod_flite/mod_flite.c.orig	2016-01-11 23:51:12.000000000 +0000
+++ src/mod/asr_tts/mod_flite/mod_flite.c
@@ -31,7 +31,7 @@
  */
 
 #include <switch.h>
-#include <flite.h>
+#include <flite/flite.h>
 
 cst_voice *register_cmu_us_awb(void);
 void unregister_cmu_us_awb(cst_voice * v);

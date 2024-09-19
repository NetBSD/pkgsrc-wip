$NetBSD$

"Invalid scheduling priority (maximum 63)."

--- xwax.c.orig	2018-01-19 20:40:49.000000000 +0000
+++ xwax.c
@@ -49,7 +49,12 @@
 #define DEFAULT_ALSA_BUFFER 8 /* milliseconds */
 
 #define DEFAULT_RATE 44100
+
+#ifdef __NetBSD__
+#define DEFAULT_PRIORITY 63
+#else
 #define DEFAULT_PRIORITY 80
+#endif
 
 #define DEFAULT_IMPORTER EXECDIR "/xwax-import"
 #define DEFAULT_SCANNER EXECDIR "/xwax-scan"

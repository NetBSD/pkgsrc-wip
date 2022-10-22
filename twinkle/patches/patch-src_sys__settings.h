$NetBSD$

* use /dev/audio as standard device on NetBSD

--- src/sys_settings.h.orig	2022-02-19 05:05:00.000000000 +0000
+++ src/sys_settings.h
@@ -40,7 +40,11 @@ using namespace std;
 #define DIR_TMPFILE	"tmp"
 
 /** Device file for DSP */
+#ifdef __NetBSD__
+#define DEV_DSP		"/dev/audio"
+#else
 #define DEV_DSP		"/dev/dsp"
+#endif
 
 /** Device prefixes in settings file */
 #define PFX_OSS		"oss:"

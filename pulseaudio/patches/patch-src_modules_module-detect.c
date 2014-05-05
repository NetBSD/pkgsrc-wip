$NetBSD: patch-src_modules_module-detect.c,v 1.1 2014/05/05 23:57:08 ryo-on Exp $

--- src/modules/module-detect.c.orig	2014-01-23 18:57:55.000000000 +0000
+++ src/modules/module-detect.c
@@ -122,6 +122,7 @@ static int detect_oss(pa_core *c, int ju
     FILE *f;
     int n = 0, b = 0;
 
+#if !defined(__NetBSD__)
     if (!(f = pa_fopen_cloexec("/dev/sndstat", "r")) &&
         !(f = pa_fopen_cloexec("/proc/sndstat", "r")) &&
         !(f = pa_fopen_cloexec("/proc/asound/oss/sndstat", "r"))) {
@@ -173,6 +174,14 @@ static int detect_oss(pa_core *c, int ju
     }
 
     fclose(f);
+#else
+/* dummy */
+    char args[64];
+    pa_snprintf(args, sizeof(args), "device=/dev/sound");
+    if (!pa_module_load(c, "module-oss", args))
+	exit(1);
+    n = 1;
+#endif
     return n;
 }
 #endif

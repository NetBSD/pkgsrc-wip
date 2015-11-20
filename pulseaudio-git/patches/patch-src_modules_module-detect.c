$NetBSD: patch-src_modules_module-detect.c,v 1.2 2014/06/25 15:26:40 ryoon Exp $

Hack to set proper sound device on NetBSD.

--- src/modules/module-detect.c.orig	2015-09-10 04:51:41.000000000 +0000
+++ src/modules/module-detect.c
@@ -120,6 +120,17 @@ static int detect_oss(pa_core *c, int ju
     FILE *f;
     int n = 0, b = 0;
 
+#if defined(__NetBSD__)
+/*
+ * Assume primary sound device is used (/dev/audio).
+ * And only primary sound device will be used (n=1).
+ */
+    char args[64];
+    pa_snprintf(args, sizeof(args), "device=/dev/audio");
+    if (!pa_module_load(c, "module-oss", args))
+	exit(1);
+    n = 1;
+#else /* __linux__ or __FreeBSD__ */
     if (!(f = pa_fopen_cloexec("/dev/sndstat", "r")) &&
         !(f = pa_fopen_cloexec("/proc/sndstat", "r")) &&
         !(f = pa_fopen_cloexec("/proc/asound/oss/sndstat", "r"))) {
@@ -171,6 +182,7 @@ static int detect_oss(pa_core *c, int ju
     }
 
     fclose(f);
+#endif
     return n;
 }
 #endif

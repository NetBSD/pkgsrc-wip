$NetBSD: patch-mono_mini_mini-arm.c,v 1.5 2015/05/21 14:38:08 kefren Exp $

--- mono/mini/mini-arm.c.orig	2016-08-03 10:33:31.000000000 +0000
+++ mono/mini/mini-arm.c
@@ -900,6 +900,32 @@ mono_arch_init (void)
 	   have a way to properly detect CPU features on it. */
 	thumb_supported = TRUE;
 	iphone_abi = TRUE;
+#elif defined(__NetBSD__)
+	if (sysctlbyname("machdep.cpu_arch", NULL, &len, NULL, 0) < 0) {
+		/* sysctlbyname error */
+		return;
+	}
+	s = malloc(len);
+	if (sysctlbyname("machdep.cpu_arch", s, &len, NULL, 0) < 0) {
+		/* sysctlbyname error */
+		free(s);
+		return;
+	}
+
+	switch (s[0]) {
+	case '7':
+		v7_supported = TRUE;
+		/* FALLTHROUGH */
+	case '6':
+		v6_supported = TRUE;
+		/* FALLTHROUGH */
+	case '5':
+		v5_supported = TRUE;
+		break;
+	}
+
+	free(s);
+	
 #else
 	thumb_supported = mono_hwcap_arm_has_thumb;
 	thumb2_supported = mono_hwcap_arm_has_thumb2;

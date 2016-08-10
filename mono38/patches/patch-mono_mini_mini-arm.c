$NetBSD: patch-mono_mini_mini-arm.c,v 1.5 2015/05/21 14:38:08 kefren Exp $

--- mono/mini/mini-arm.c.orig	2014-09-04 07:25:40.000000000 +0000
+++ mono/mini/mini-arm.c
@@ -54,6 +54,11 @@
 #define IS_VFP (TRUE)
 #endif
 
+#ifdef __NetBSD__
+#include <machine/sysarch.h>
+#include <sys/sysctl.h>
+#endif
+
 #if defined(__ARM_EABI__) && defined(__linux__) && !defined(PLATFORM_ANDROID) && !defined(__native_client__)
 #define HAVE_AEABI_READ_TP 1
 #endif
@@ -941,6 +946,32 @@ mono_arch_init (void)
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

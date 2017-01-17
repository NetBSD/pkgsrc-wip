$NetBSD: patch-src_sna_sna__display.c,v 1.1 2015/05/22 05:40:36 richard Exp $

SunOS needs <alloca.h> for alloca()

DragonFly dports some version ignored xf86ReturnOptValBool()

--- src/sna/sna_display.c.orig	2014-12-20 13:45:31.000000000 +0000
+++ src/sna/sna_display.c
@@ -72,6 +72,9 @@
 #include <memcheck.h>
 #endif
 
+#ifdef __sun
+#include <alloca.h>
+#endif
 /* Minor discrepancy between 32-bit/64-bit ABI in old kernels */
 union compat_mode_get_connector{
 	struct drm_mode_get_connector conn;
@@ -5543,7 +5546,11 @@ static bool sna_probe_initial_configurat
 			OPTION_ROTATE,
 			OPTION_PANNING,
 		};
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
+		if (xf86ReturnOptValBool(sna->Options, OPTION_REPROBE, FALSE) || 1) {
+#else
 		if (xf86ReturnOptValBool(sna->Options, OPTION_REPROBE, FALSE)) {
+#endif
 			DBG(("%s: user requests reprobing\n", __FUNCTION__));
 			return false;
 		}

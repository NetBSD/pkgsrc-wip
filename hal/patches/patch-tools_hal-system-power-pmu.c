$NetBSD$

--- tools/hal-system-power-pmu.c.orig	2009-05-12 12:25:58.000000000 +0000
+++ tools/hal-system-power-pmu.c
@@ -55,6 +55,10 @@ pmac_sleep (void)
 {
 #if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
 	return FALSE;			/* FIXME implement */
+#elif __NetBSD__
+	return FALSE;			/* FIXME implement */
+#elif __DragonFly__
+	return FALSE;			/* FIXME implement */
 #elif sun
 	return FALSE;			/* FIXME implement */
 #elif __GNU__
@@ -92,6 +96,10 @@ pmac_get_lcd_brightness (int *val)
 {
 #if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
 	return FALSE;			/* FIXME implement */
+#elif __NetBSD__
+	return FALSE;			/* FIXME implement */
+#elif __DragonFly__
+	return FALSE;			/* FIXME implement */
 #elif sun
 	return FALSE;			/* FIXME implement */
 #elif __GNU__
@@ -129,6 +137,10 @@ pmac_set_lcd_brightness (int val)
 {
 #if defined (__FreeBSD__) || defined(__FreeBSD_kernel__)
 	return FALSE;			/* FIXME implement */
+#elif __NetBSD__
+	return FALSE;			/* FIXME implement */
+#elif __DragonFly__
+	return FALSE;			/* FIXME implement */
 #elif sun
 	return FALSE;			/* FIXME implement */
 #elif __GNU__

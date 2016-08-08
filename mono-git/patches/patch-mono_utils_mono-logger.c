$NetBSD$

--- mono/utils/mono-logger.c.orig	2016-08-08 17:23:32.000000000 +0000
+++ mono/utils/mono-logger.c
@@ -366,7 +366,7 @@ legacy_opener(const char *path, void *us
  * Cleanup routine for older style loggers
  */
 static void
-legacy_closer()
+legacy_closer(void)
 {
 	if (logCallback.user_data != NULL) {
 		g_free (logCallback.user_data); /* This is a LegacyLoggerUserData struct */

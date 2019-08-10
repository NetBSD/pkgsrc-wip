$NetBSD$

--- config.c.orig	2019-06-15 23:36:40.000000000 +0000
+++ config.c
@@ -27,7 +27,9 @@
 #include "velox.h"
 
 #include <fcntl.h>
+#ifdef __linux__
 #include <linux/input.h>
+#endif
 #include <spawn.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -291,6 +293,7 @@ parse_key(char *s, uint32_t *value)
 static bool
 parse_button(char *s, uint32_t *value)
 {
+#ifndef __NetBSD__
 	if (strcmp(s, "left") == 0)
 		*value = BTN_LEFT;
 	else if (strcmp(s, "right") == 0)
@@ -303,7 +306,7 @@ parse_button(char *s, uint32_t *value)
 		*value = BTN_EXTRA;
 	else
 		return false;
-
+#endif
 	return true;
 }
 

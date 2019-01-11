$NetBSD$

Use system libcanlock.

--- include/tin.h.orig
+++ include/tin.h
@@ -2394,7 +2394,7 @@ extern struct tm *localtime(time_t *);
 
 /* libcanlock */
 #ifdef USE_CANLOCK
-#	include "../libcanlock/include/canlock.h"
+#	include <libcanlock-3/canlock.h>
 #endif /* USE_CANLOCK */
 
 /* gsasl */

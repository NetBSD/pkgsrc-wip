$NetBSD$

Add mising #ifdef for NetBSD. Backport of existing upstream patch.
Merged upstream: https://git.enlightenment.org/enlightenment/efl/pulls/130

--- src/lib/eet/eet_image.c.orig	2026-08-29 17:54:55.289546854 +0000
+++ src/lib/eet/eet_image.c
@@ -2,9 +2,9 @@
 # include <config.h>
 #endif /* ifdef HAVE_CONFIG_H */
 
-#ifdef __OpenBSD__
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 # include <sys/types.h>
-#endif /* ifdef __OpenBSD__ */
+#endif
 
 #include <stdio.h>
 #include <string.h>

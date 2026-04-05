$NetBSD$

Add npflog0 to ignored interfaces.

--- src/ifinfo.c.orig	2025-01-07 19:57:18.000000000 +0000
+++ src/ifinfo.c	2026-04-05 21:34:38.850795078 +0000
@@ -488,6 +488,8 @@
 		return 0;
 	} else if (strcmp(iface, "lo0") == 0) {
 		return 0;
+	} else if (strcmp(iface, "npflog0") == 0) {
+		return 0;
 	} else if (strcmp(iface, "sit0") == 0) {
 		return 0;
 	}

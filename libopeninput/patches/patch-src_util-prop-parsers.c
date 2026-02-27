$NetBSD$

* Fix ctype usage

--- src/util-prop-parsers.c.orig	2026-02-27 15:55:33.037318106 +0100
+++ src/util-prop-parsers.c
@@ -65,7 +65,7 @@ parse_mouse_dpi_property(const char *pro
 		if (*prop == '*') {
 			prop++;
 			is_default = true;
-			if (!isdigit(prop[0]))
+			if (!isdigit((unsigned char)prop[0]))
 				return 0;
 		}
 

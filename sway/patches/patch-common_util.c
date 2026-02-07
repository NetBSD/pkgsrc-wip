$NetBSD$

* Fix ctype usage

--- common/util.c.orig	2026-02-06 14:12:13.396723268 +0000
+++ common/util.c
@@ -18,7 +18,7 @@ bool parse_color(const char *color, uint
 		++color;
 	}
 	int len = strlen(color);
-	if ((len != 6 && len != 8) || !isxdigit(color[0]) || !isxdigit(color[1])) {
+	if ((len != 6 && len != 8) || !isxdigit((unsigned char)color[0]) || !isxdigit((unsigned char)color[1])) {
 		return false;
 	}
 	char *ptr;

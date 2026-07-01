$NetBSD$

Prevent undefined behaviour of isspacer().

--- src/textures/config.c.orig	2025-12-09 03:51:38.000000000 +0000
+++ src/textures/config.c
@@ -119,7 +119,7 @@ static void StripTrailingSpaces(char *li
 	char *p = line + strlen(line);
 	while (p > line) {
 		--p;
-		if (!isspace(*p)) {
+		if (!isspace((unsigned char) *p)) {
 			break;
 		}
 		*p = '\0';

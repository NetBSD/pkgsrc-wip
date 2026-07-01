$NetBSD$

Prevent undefined behaviour of tolower().

--- src/pager/pager.c.orig	2025-12-09 03:51:38.000000000 +0000
+++ src/pager/pager.c
@@ -102,7 +102,7 @@ static bool LineContainsString(struct pa
 	for (i = 0; i < w - needle_len; i++) {
 		for (j = 0; needle[j] != '\0'; j++) {
 			int c = mvwinch(p->search_pad, 0, i + j);
-			if (tolower(needle[j]) != tolower(c & A_CHARTEXT)) {
+			if (tolower((unsigned char) needle[j]) != tolower((unsigned char) (c & A_CHARTEXT))) {
 				break;
 			}
 		}

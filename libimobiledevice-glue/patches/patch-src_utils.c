$NetBSD$

Fix ctype(3) usage.

--- src/utils.c.orig	2025-07-31 18:18:48.354814064 +0000
+++ src/utils.c
@@ -220,7 +220,7 @@ char *string_toupper(char* str)
 	char *res = strdup(str);
 	size_t i;
 	for (i = 0; i < strlen(res); i++) {
-		res[i] = toupper(res[i]);
+		res[i] = toupper((unsigned char)res[i]);
 	}
 	return res;
 }

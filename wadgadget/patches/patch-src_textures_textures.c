$NetBSD$

Prevent undefined behaviour of toupper().

--- src/textures/textures.c.orig	2025-12-09 03:51:38.000000000 +0000
+++ src/textures/textures.c
@@ -259,7 +259,7 @@ static void SetTextureName(struct textur
 	int i;
 
 	for (i = 0; i < 8; i++) {
-		namedest[i] = toupper(name[i]);
+		namedest[i] = toupper((unsigned char) name[i]);
 		if (namedest[i] == '\0') {
 			break;
 		}

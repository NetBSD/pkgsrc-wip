$NetBSD$

Prevent undefined behaviour of toupper().

--- src/textures/pnames.c.orig	2025-12-09 03:51:38.000000000 +0000
+++ src/textures/pnames.c
@@ -132,7 +132,7 @@ void TX_RenamePname(struct pnames *pn, u
 
 	namedest = pn->pnames[idx];
 	for (i = 0; i < 8; i++) {
-		namedest[i] = toupper(name[i]);
+		namedest[i] = toupper((unsigned char) name[i]);
 		if (namedest[i] == '\0') {
 			break;
 		}

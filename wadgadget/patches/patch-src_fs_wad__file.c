$NetBSD$

Prevent undefined behaviour of toupper().

--- src/fs/wad_file.c.orig	2025-12-09 03:51:38.000000000 +0000
+++ src/fs/wad_file.c
@@ -316,7 +316,7 @@ void W_SetLumpName(struct wad_file *f, u
 	assert(!f->readonly);
 	assert(index < f->num_lumps);
 	for (i = 0; i < 8; i++) {
-		f->directory[index].name[i] = toupper(name[i]);
+		f->directory[index].name[i] = toupper((unsigned char) name[i]);
 		if (name[i] == '\0') {
 			break;
 		}

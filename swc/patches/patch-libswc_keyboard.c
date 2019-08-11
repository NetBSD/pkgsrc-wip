$NetBSD$

--- libswc/keyboard.c.orig	2019-07-11 06:33:41.000000000 +0000
+++ libswc/keyboard.c
@@ -150,10 +150,12 @@ update_keymap(struct xkb *xkb)
 
 	unlink(keymap_path);
 
+#ifndef __NetBSD__
 	if (posix_fallocate(xkb->keymap.fd, 0, xkb->keymap.size) != 0) {
 		WARNING("Could not resize XKB keymap file\n");
 		goto error2;
 	}
+#endif
 
 	xkb->keymap.area = mmap(NULL, xkb->keymap.size, PROT_READ | PROT_WRITE, MAP_SHARED, xkb->keymap.fd, 0);
 

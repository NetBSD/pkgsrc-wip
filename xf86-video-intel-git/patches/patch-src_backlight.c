$NetBSD$

Fix forward declaration.

--- src/backlight.c.orig	2015-09-22 17:33:34.000000000 +0000
+++ src/backlight.c
@@ -532,6 +532,8 @@ void backlight_close(struct backlight *b
 		waitpid(b->pid, NULL, 0);
 }
 
+static int __backlight_exists(const char *iface);
+
 char *backlight_find_for_device(struct pci_device *pci)
 {
 	char path[200];

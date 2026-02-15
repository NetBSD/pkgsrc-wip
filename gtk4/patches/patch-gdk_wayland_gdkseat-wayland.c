$NetBSD$

Allow building on systems without evdev

--- gdk/wayland/gdkseat-wayland.c.orig	2026-02-15 09:56:56.344100295 +0000
+++ gdk/wayland/gdkseat-wayland.c
@@ -48,6 +48,14 @@
 #include <dev/evdev/input.h>
 #elif defined(HAVE_LINUX_INPUT_H)
 #include <linux/input.h>
+#else
+#ifndef BTN_LEFT
+#define BTN_LEFT	(0x110)
+#define BTN_RIGHT	(0x111)
+#define BTN_MIDDLE	(0x112)
+#define BTN_STYLUS	(0x14b)
+#define BTN_STYLUS2	(0x14c)
+#endif
 #endif
 
 /**

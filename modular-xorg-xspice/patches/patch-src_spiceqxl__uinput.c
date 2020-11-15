$NetBSD$

Provide the necessary defintions for non-linux.

--- src/spiceqxl_uinput.c.orig	2016-03-23 17:14:16.000000000 +0000
+++ src/spiceqxl_uinput.c
@@ -9,8 +9,25 @@
 #include <errno.h>
 #include <stdio.h>
 
+#ifdef __linux__
 #include <linux/input.h>
 #include <linux/uinput.h>
+#else
+struct input_event {
+    struct timeval time;
+    uint16_t type;
+    uint16_t code;
+    int32_t value;
+};
+#define ABS_X			0x00
+#define ABS_Y			0x01
+#define BTN_LEFT		0x110
+#define BTN_RIGHT		0x111
+#define BTN_MIDDLE		0x112
+#define EV_KEY			0x01
+#define EV_REL			0x02
+#define EV_ABS			0x03
+#endif
 
 #include "qxl_option_helpers.h"
 #include "spiceqxl_util.h"

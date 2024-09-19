$NetBSD$

Changes from NetBSD xsrc xorg-server 1.20.5.

Patch from OpenBSD xenocara for "ws" driver.

--- config/wscons.c.orig	2019-05-30 18:27:34.000000000 +0000
+++ config/wscons.c
@@ -25,14 +25,17 @@
 #include <dix-config.h>
 #endif
 
-#include <dev/wscons/wsconsio.h>
-#include <dev/wscons/wsksymdef.h>
-
+#include <sys/types.h>
 #include <sys/ioctl.h>
+#include <sys/time.h>
+#include <fcntl.h>
 #include <errno.h>
 #include <string.h>
 #include <unistd.h>
 
+#include <dev/wscons/wsconsio.h>
+#include <dev/wscons/wsksymdef.h>
+
 #include "input.h"
 #include "inputstr.h"
 #include "os.h"
@@ -41,6 +44,7 @@
 #define WSCONS_KBD_DEVICE "/dev/wskbd"
 #define WSCONS_MOUSE_PREFIX "/dev/wsmouse"
 
+#if defined(KB_LA) && defined(KB_CF)
 #define KB_OVRENC \
 	{ KB_UK,	"gb" }, \
 	{ KB_SV,	"se" }, \
@@ -48,13 +52,27 @@
 	{ KB_SF,	"ch" }, \
 	{ KB_LA,	"latam" }, \
 	{ KB_CF,	"ca" }
+#else
+#define KB_OVRENC \
+	{ KB_UK,	"gb" }, \
+	{ KB_SV,	"se" }, \
+	{ KB_SG,	"ch" }, \
+	{ KB_SF,	"ch" }
+#endif
 
 struct nameint {
     int val;
     char *name;
 } kbdenc[] = {
     KB_OVRENC,
+#if defined(STRICT_XSRC_NETBSD)
+    KB_ENCTAB
+#ifndef __NetBSD__
+             ,
+#endif
+#else /* !STRICT_XSRC_NETBSD */
     KB_ENCTAB,
+#endif /* STRICT_XSRC_NETBSD */
     {0}
 };
 
@@ -62,10 +80,14 @@ struct nameint kbdvar[] = {
     {KB_NODEAD | KB_SG, "de_nodeadkeys"},
     {KB_NODEAD | KB_SF, "fr_nodeadkeys"},
     {KB_SF, "fr"},
+#if defined(KB_CF)
     {KB_DVORAK | KB_CF, "fr-dvorak"},
+#endif
     {KB_DVORAK | KB_FR, "bepo"},
     {KB_DVORAK, "dvorak"},
+#if defined(KB_CF)
     {KB_CF, "fr-legacy"},
+#endif
     {KB_NODEAD, "nodeadkeys"},
     {0}
 };
@@ -121,8 +143,12 @@ wscons_add_keyboard(void)
     input_options = input_option_new(input_options, "name", WSCONS_KBD_DEVICE);
     input_options = input_option_new(input_options, "driver", "kbd");
 
+#if defined(STRICT_XSRC_NETBSD)
+    if (asprintf(&config_info, "wscons:%s", WSCONS_KBD_DEVICE) != -1)
+#else
     config_info = Xprintf("wscons:%s", WSCONS_KBD_DEVICE);
     if (!config_info)
+#endif
         goto unwind;
     if (KB_ENCODING(wsenc) == KB_USER) {
         /* Ignore wscons "user" layout */
@@ -185,8 +211,12 @@ wscons_add_pointer(const char *path, con
     char *config_info = NULL;
     int rc;
 
+#if defined(STRICT_XSRC_NETBSD)
+    if (asprintf(&config_info, "wscons:%s", path) == -1)
+#else
     config_info = Xprintf("wscons:%s", path);
     if (!config_info)
+#endif
         return;
 
     input_options = input_option_new(input_options, "_source", "server/wscons");
@@ -220,7 +250,11 @@ wscons_add_pointers(void)
     for (i = 0; i < 4; i++) {
         snprintf(devname, sizeof(devname), "%s%d", WSCONS_MOUSE_PREFIX, i);
         LogMessageVerb(X_INFO, 10, "wsmouse: checking %s\n", devname);
-        fd = open_device(devnamem O_RDWR | O_NONBLOCK | O_EXCL);
+#ifdef __NetBSD__
+        fd = open(devname, O_RDWR | O_NONBLOCK | O_EXCL);
+#else
+        fd = open_device(devname, O_RDWR | O_NONBLOCK | O_EXCL);
+#endif
         if (fd == -1) {
             LogMessageVerb(X_WARNING, 10, "%s: %s\n", devname, strerror(errno));
             continue;
@@ -233,9 +267,11 @@ wscons_add_pointers(void)
         }
         close(fd);
         switch (wsmouse_type) {
+#if defined(WSMOUSE_TYPE_SYNAPTICS)
         case WSMOUSE_TYPE_SYNAPTICS:
             wscons_add_pointer(devname, "synaptics", ATTR_TOUCHPAD);
             break;
+#endif
         case WSMOUSE_TYPE_TPANEL:
             wscons_add_pointer(devname, "ws", ATTR_TOUCHSCREEN);
             break;
@@ -243,8 +279,13 @@ wscons_add_pointers(void)
             break;
         }
     }
+#if defined(WS_DRIVERS_OPENBSD)
+    /* Add a default entry catching all other mux elements as "ws" */
+    wscons_add_pointer(WSCONS_MOUSE_PREFIX, "ws", ATTR_POINTER);
+#else
     /* Add a default entry catching all other mux elements as "mouse" */
     wscons_add_pointer(WSCONS_MOUSE_PREFIX, "mouse", ATTR_POINTER);
+#endif
 }
 
 int

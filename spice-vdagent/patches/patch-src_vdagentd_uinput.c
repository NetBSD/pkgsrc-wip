$NetBSD$

Add NetBSD support.

--- src/vdagentd/uinput.c.orig	2019-02-11 11:16:16.000000000 +0000
+++ src/vdagentd/uinput.c
@@ -26,12 +26,15 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <errno.h>
+#if defined(__linux__)
 #include <linux/input.h>
 #include <linux/uinput.h>
+#endif
 #include <spice/vd_agent.h>
 #include <glib.h>
 #include "uinput.h"
 
+#if defined(__linux__)
 struct vdagentd_uinput {
     const char *devname;
     int fd;
@@ -265,3 +268,31 @@ void vdagentd_uinput_do_mouse(struct vda
     if (*uinputp)
         uinput->last = *mouse;
 }
+#elif defined(__NetBSD__)
+struct vdagentd_uinput {
+};
+
+void vdagentd_uinput_do_mouse(struct vdagentd_uinput **uinputp,
+        VDAgentMouseState *mouse)
+{
+}
+
+void vdagentd_uinput_destroy(struct vdagentd_uinput **uinputp)
+{
+}
+
+void vdagentd_uinput_update_size(struct vdagentd_uinput **uinputp,
+        int width, int height,
+        struct vdagentd_guest_xorg_resolution *screen_info,
+        int screen_count)
+{
+}
+
+struct vdagentd_uinput *vdagentd_uinput_create(const char *devname,
+    int width, int height,
+    struct vdagentd_guest_xorg_resolution *screen_info, int screen_count,
+    int debug, int fake)
+{
+	return NULL;
+}
+#endif

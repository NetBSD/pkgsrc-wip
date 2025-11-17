$NetBSD$

--- third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc.orig	2025-11-17 00:50:40.297687435 +0000
+++ third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -11,7 +11,9 @@
 #include "modules/desktop_capture/linux/wayland/egl_dmabuf.h"
 
 #include <EGL/eglext.h>
+#if defined(__linux__)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <gdk/gdk.h>

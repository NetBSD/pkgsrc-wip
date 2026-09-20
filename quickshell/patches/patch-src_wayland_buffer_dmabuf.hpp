$NetBSD$

* Fix buildtime X11 header pollution
  - Example:
In file included from /usr/X11R7/include/X11/Xlib.h:44,
                 from /usr/X11R7/include/EGL/eglplatform.h:134,
                 from /usr/X11R7/include/EGL/egl.h:20,
                 from /usr/pkgsrc/wip/quickshell/work/quickshell/src/wayland/buffer/dmabuf.hpp:7,
                 from /usr/pkgsrc/wip/quickshell/work/quickshell/src/wayland/buffer/manager.cpp:18:
/usr/pkg/qt6/include/QtQuick/qsgtexture.h:35:9: error:
 expected identifier before numeric constant
 35 | None,
    | ^~~~

  - Reference: https://github.com/WebKit/WebKit/pull/64743

--- src/wayland/buffer/dmabuf.hpp.orig	2026-09-19 12:48:33.265710780 +0000
+++ src/wayland/buffer/dmabuf.hpp
@@ -5,6 +5,20 @@
 #include <memory>
 
 #include <EGL/egl.h>
+
+#ifdef None
+#undef None
+#endif
+#ifdef Bool
+#undef Bool
+#endif
+#ifdef Status
+#undef Status
+#endif
+#ifdef Always
+#undef Always
+#endif
+
 #include <gbm.h>
 #include <qcontainerfwd.h>
 #include <qhash.h>

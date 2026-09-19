$NetBSD$

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

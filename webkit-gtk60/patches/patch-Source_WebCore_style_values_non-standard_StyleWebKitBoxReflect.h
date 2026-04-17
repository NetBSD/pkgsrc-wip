$NetBSD$

In file included from /usr/pkg/include/X11/Xlib.h:44,
                 from /usr/pkg/include/EGL/eglplatform.h:134,
                 from /usr/pkg/include/epoxy/egl_generated.h:11,
                 from /usr/pkg/include/epoxy/egl.h:46,
                 from /tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/ThreadedCompositor.cpp:50,
                 from /tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/cmake-pkgsrc-build/DerivedSources/WebKit/unified-sources/UnifiedSource-54928a2b-33.cpp:1:
/tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/cmake-pkgsrc-build/WebCore/PrivateHeaders/WebCore/StyleWebKitBoxReflect.h:40:58: error: expected unqualified-id before numeric constant
   40 |     ReflectionDirection direction { ReflectionDirection::Below };
      |                                                          ^~~~~


--- Source/WebCore/style/values/non-standard/StyleWebKitBoxReflect.h.orig	2026-04-17 09:12:46.751122658 +0000
+++ Source/WebCore/style/values/non-standard/StyleWebKitBoxReflect.h
@@ -29,6 +29,10 @@
 #include <WebCore/StyleLengthWrapper.h>
 #include <WebCore/StyleMaskBorder.h>
 
+#ifdef Below
+#undef Below
+#endif
+
 namespace WebCore {
 namespace Style {
 

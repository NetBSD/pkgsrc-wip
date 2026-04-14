$NetBSD$

In file included from /usr/pkg/include/X11/Xlib.h:44,
                 from /usr/pkg/include/EGL/eglplatform.h:134,
                 from /usr/pkg/include/epoxy/egl_generated.h:11,
                 from /usr/pkg/include/epoxy/egl.h:46,
                 from /tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/ThreadedCompositor.cpp:50,
                 from /tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/cmake-pkgsrc-build/DerivedSources/WebKit/unified-sources/UnifiedSource-54928a2b-46.cpp:4:
/tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/cmake-pkgsrc-build/WebCore/PrivateHeaders/WebCore/FrameSelection.h:138:55: error: expected identifier before numeric constant
  138 |     enum class CursorAlignOnScroll : bool { IfNeeded, Always };
      |                                                       ^~~~~~

--- Source/WebCore/editing/FrameSelection.h.orig	2026-04-14 16:14:56.876999207 +0000
+++ Source/WebCore/editing/FrameSelection.h
@@ -39,6 +39,10 @@
 #include <wtf/Platform.h>
 #include <wtf/TZoneMalloc.h>
 
+#ifdef Always
+#undef Always
+#endif
+
 namespace WebCore {
 
 class CharacterData;

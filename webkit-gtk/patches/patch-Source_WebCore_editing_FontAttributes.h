$NetBSD$

In file included from /usr/pkg/include/X11/Xlib.h:44,
                 from /usr/pkg/include/EGL/eglplatform.h:134,
                 from /usr/pkg/include/epoxy/egl_generated.h:11,
                 from /usr/pkg/include/epoxy/egl.h:46,
                 from /tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/ThreadedCompositor.cpp:50,
                 from /tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/cmake-pkgsrc-build/DerivedSources/WebKit/unified-sources/UnifiedSource-54928a2b-46.cpp:4:
/tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/cmake-pkgsrc-build/WebCore/PrivateHeaders/WebCore/FontAttributes.h:42:52: error: expected unqualified-id before numeric constant
   42 |     Style::ListStyleType styleType { CSS::Keyword::None { } };
      |                                                    ^~~~

--- Source/WebCore/editing/FontAttributes.h.orig	2026-04-14 14:43:02.330262736 +0000
+++ Source/WebCore/editing/FontAttributes.h
@@ -36,6 +36,10 @@ OBJC_CLASS NSTextList;
 OBJC_CLASS NSDictionary;
 OBJC_CLASS NSTextList;
 
+#ifdef None
+#undef None
+#endif
+
 namespace WebCore {
 
 struct TextList {

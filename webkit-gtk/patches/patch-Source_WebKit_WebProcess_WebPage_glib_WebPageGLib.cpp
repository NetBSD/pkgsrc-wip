$NetBSD$

In file included from /usr/pkg/include/EGL/eglplatform.h:134,
                 from /usr/pkg/include/epoxy/egl_generated.h:11,
                 from /usr/pkg/include/epoxy/egl.h:46,
                 from /tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/ThreadedCompositor.cpp:50,
                 from /tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/cmake-pkgsrc-build/DerivedSources/WebKit/unified-sources/UnifiedSource-54928a2b-46.cpp:4:
/tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/Source/WebKit/WebProcess/WebPage/glib/WebPageGLib.cpp: In member function 'void WebKit::WebPage::getPlatformEditorState(WebCore::LocalFrame&, WebKit::EditorState&) const':
/tmp/wip/webkit-gtk/work/webkitgtk-2.52.2/Source/WebKit/WebProcess/WebPage/glib/WebPageGLib.cpp:139:84: error: expected unqualified-id before numeric constant
  139 |         if (editor.selectionHasStyle(CSSPropertyFontWeight, "bold"_s) == TriState::True)
      |                                                                                    ^~~~

--- Source/WebKit/WebProcess/WebPage/glib/WebPageGLib.cpp.orig	2026-04-14 16:52:45.150237443 +0000
+++ Source/WebKit/WebProcess/WebPage/glib/WebPageGLib.cpp
@@ -66,6 +66,10 @@
 #include <xf86drm.h>
 #endif
 
+#ifdef True
+#undef True
+#endif
+
 namespace WebKit {
 using namespace WebCore;
 

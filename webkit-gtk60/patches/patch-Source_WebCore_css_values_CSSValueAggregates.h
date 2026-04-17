$NetBSD$

In file included from /usr/pkg/include/X11/Xlib.h:44,
                 from /usr/pkg/include/EGL/eglplatform.h:134,
                 from /usr/pkg/include/epoxy/egl_generated.h:11,
                 from /usr/pkg/include/epoxy/egl.h:46,
                 from /tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/Source/WebKit/WebProcess/WebPage/CoordinatedGraphics/ThreadedCompositor.cpp:50,
                 from /tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/cmake-pkgsrc-build/DerivedSources/WebKit/unified-sources/UnifiedSource-54928a2b-33.cpp:1:
/tmp/wip/webkit-gtk60/work/webkitgtk-2.52.3/cmake-pkgsrc-build/WebCore/PrivateHeaders/WebCore/CSSValueAggregates.h:47:51: error: expected identifier before numeric constant
   47 | enum class SerializationSeparatorType : uint8_t { None, Space, Comma, Slash };
      |                                                   ^~~~

--- Source/WebCore/css/values/CSSValueAggregates.h.orig	2026-04-17 07:47:59.331171195 +0000
+++ Source/WebCore/css/values/CSSValueAggregates.h
@@ -42,6 +42,10 @@
 #include <wtf/text/AtomString.h>
 #include <wtf/text/TextStream.h>
 
+#ifdef None
+#undef None
+#endif
+
 namespace WebCore {
 
 enum class SerializationSeparatorType : uint8_t { None, Space, Comma, Slash };

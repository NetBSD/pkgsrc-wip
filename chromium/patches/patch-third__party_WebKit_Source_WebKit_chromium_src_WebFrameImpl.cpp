$NetBSD: patch-third__party_WebKit_Source_WebKit_chromium_src_WebFrameImpl.cpp,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- third_party/WebKit/Source/WebKit/chromium/src/WebFrameImpl.cpp.orig	2011-05-24 08:03:03.000000000 +0000
+++ third_party/WebKit/Source/WebKit/chromium/src/WebFrameImpl.cpp
@@ -154,7 +154,7 @@
 #include <algorithm>
 #include <wtf/CurrentTime.h>
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
 #include <gdk/gdk.h>
 #endif
 
@@ -324,7 +324,7 @@ public:
         float scale = m_printedPageWidth / pageRect.width();
 
         ctx.save();
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
         ctx.scale(WebCore::FloatSize(scale, scale));
 #endif
         ctx.translate(static_cast<float>(-pageRect.x()),

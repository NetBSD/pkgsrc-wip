$NetBSD: patch-third__party_WebKit_Source_WebKit_chromium_src_WebFrameImpl.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebKit/chromium/src/WebFrameImpl.cpp.orig	2011-04-13 08:12:09.000000000 +0000
+++ third_party/WebKit/Source/WebKit/chromium/src/WebFrameImpl.cpp
@@ -159,7 +159,7 @@
 #include "LocalCurrentGraphicsContext.h"
 #endif
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
 #include <gdk/gdk.h>
 #endif
 
@@ -322,7 +322,7 @@ public:
         float scale = m_printedPageWidth / pageRect.width();
 
         ctx.save();
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
         ctx.scale(WebCore::FloatSize(scale, scale));
 #endif
         ctx.translate(static_cast<float>(-pageRect.x()),
@@ -1338,7 +1338,7 @@ float WebFrameImpl::printPage(int page, 
         return 0;
     }
 
-#if OS(WINDOWS) || OS(LINUX) || OS(FREEBSD) || OS(SOLARIS)
+#if OS(WINDOWS) || OS(LINUX) || OS(BSD) || OS(SOLARIS)
     PlatformContextSkia context(canvas);
     GraphicsContext spool(&context);
 #elif OS(DARWIN)

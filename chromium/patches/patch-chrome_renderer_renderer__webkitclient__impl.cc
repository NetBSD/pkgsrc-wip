$NetBSD: patch-chrome_renderer_renderer__webkitclient__impl.cc,v 1.2 2011/05/27 13:23:09 rxg Exp $

--- chrome/renderer/renderer_webkitclient_impl.cc.orig	2011-05-24 08:01:44.000000000 +0000
+++ chrome/renderer/renderer_webkitclient_impl.cc
@@ -55,7 +55,7 @@
 #include "third_party/WebKit/Source/WebKit/chromium/public/mac/WebSandboxSupport.h"
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <string>
 #include <map>
 
@@ -113,7 +113,7 @@ class RendererWebKitClientImpl::SandboxS
   virtual bool ensureFontLoaded(HFONT);
 #elif defined(OS_MACOSX)
   virtual bool loadFont(NSFont* srcFont, ATSFontContainerRef* out);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   virtual WebKit::WebString getFontFamilyForCharacters(
       const WebKit::WebUChar* characters,
       size_t numCharacters,
@@ -430,7 +430,7 @@ bool RendererWebKitClientImpl::SandboxSu
   return RenderThread::current()->Send(new ViewHostMsg_PreCacheFont(logfont));
 }
 
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 
 WebString RendererWebKitClientImpl::SandboxSupport::getFontFamilyForCharacters(
     const WebKit::WebUChar* characters,

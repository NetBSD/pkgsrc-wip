$NetBSD: patch-third__party_WebKit_Source_WebCore_page_chromium_EventHandlerChromium.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/page/chromium/EventHandlerChromium.cpp.orig	2011-04-13 08:12:22.000000000 +0000
+++ third_party/WebKit/Source/WebCore/page/chromium/EventHandlerChromium.cpp
@@ -154,7 +154,7 @@ unsigned EventHandler::accessKeyModifier
 #endif
 }
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
 // GTK+ must scroll horizontally if the mouse pointer is on top of the
 // horizontal scrollbar while scrolling with the wheel.
 // This code comes from gtk/EventHandlerGtk.cpp.

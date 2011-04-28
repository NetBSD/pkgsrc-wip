$NetBSD: patch-third__party_WebKit_Source_WebCore_page_EventHandler.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebCore/page/EventHandler.cpp.orig	2011-04-13 08:12:22.000000000 +0000
+++ third_party/WebKit/Source/WebCore/page/EventHandler.cpp
@@ -1936,7 +1936,7 @@ bool EventHandler::dispatchMouseEvent(co
     return swallowEvent;
 }
 
-#if !PLATFORM(GTK) && !(PLATFORM(CHROMIUM) && (OS(LINUX) || OS(FREEBSD)))
+#if !PLATFORM(GTK) && !(PLATFORM(CHROMIUM) && (OS(LINUX) || OS(BSD)))
 bool EventHandler::shouldTurnVerticalTicksIntoHorizontal(const HitTestResult&) const
 {
     return false;

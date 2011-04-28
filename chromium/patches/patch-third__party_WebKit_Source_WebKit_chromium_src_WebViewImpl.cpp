$NetBSD: patch-third__party_WebKit_Source_WebKit_chromium_src_WebViewImpl.cpp,v 1.1 2011/04/28 03:09:03 rxg Exp $

--- third_party/WebKit/Source/WebKit/chromium/src/WebViewImpl.cpp.orig	2011-04-13 08:12:09.000000000 +0000
+++ third_party/WebKit/Source/WebKit/chromium/src/WebViewImpl.cpp
@@ -130,7 +130,7 @@
 #if OS(WINDOWS)
 #include "RenderThemeChromiumWin.h"
 #else
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
 #include "RenderThemeChromiumLinux.h"
 #endif
 #include "RenderTheme.h"
@@ -468,7 +468,7 @@ void WebViewImpl::mouseDown(const WebMou
         || (event.button == WebMouseEvent::ButtonLeft
             && event.modifiers & WebMouseEvent::ControlKey))
         mouseContextMenu(event);
-#elif OS(LINUX) || OS(FREEBSD)
+#elif OS(LINUX) || OS(BSD)
     if (event.button == WebMouseEvent::ButtonRight)
         mouseContextMenu(event);
 #endif
@@ -507,7 +507,7 @@ void WebViewImpl::mouseUp(const WebMouse
     if (!mainFrameImpl() || !mainFrameImpl()->frameView())
         return;
 
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
     // If the event was a middle click, attempt to copy text into the focused
     // frame. We execute this before we let the page have a go at the event
     // because the page may change what is focused during in its event handler.
@@ -591,11 +591,11 @@ bool WebViewImpl::keyEvent(const WebKeyb
     if (!handler)
         return keyEventDefault(event);
 
-#if OS(WINDOWS) || OS(LINUX) || OS(FREEBSD)
+#if OS(WINDOWS) || OS(LINUX) || OS(BSD)
     const WebInputEvent::Type contextMenuTriggeringEventType =
 #if OS(WINDOWS)
         WebInputEvent::KeyUp;
-#elif OS(LINUX) || OS(FREEBSD)
+#elif OS(LINUX) || OS(BSD)
         WebInputEvent::RawKeyDown;
 #endif
 
@@ -605,7 +605,7 @@ bool WebViewImpl::keyEvent(const WebKeyb
         sendContextMenuEvent(event);
         return true;
     }
-#endif // OS(WINDOWS) || OS(LINUX) || OS(FREEBSD)
+#endif // OS(WINDOWS) || OS(LINUX) || OS(BSD)
 
     // It's not clear if we should continue after detecting a capslock keypress.
     // I'll err on the side of continuing, which is the pre-existing behaviour.
@@ -739,7 +739,7 @@ bool WebViewImpl::touchEvent(const WebTo
 }
 #endif
 
-#if OS(WINDOWS) || OS(LINUX) || OS(FREEBSD)
+#if OS(WINDOWS) || OS(LINUX) || OS(BSD)
 // Mac has no way to open a context menu based on a keyboard event.
 bool WebViewImpl::sendContextMenuEvent(const WebKeyboardEvent& event)
 {
@@ -2054,7 +2054,7 @@ void WebViewImpl::setDomainRelaxationFor
 void WebViewImpl::setScrollbarColors(unsigned inactiveColor,
                                      unsigned activeColor,
                                      unsigned trackColor) {
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
     PlatformThemeChromiumGtk::setScrollbarColors(inactiveColor,
                                                  activeColor,
                                                  trackColor);
@@ -2065,7 +2065,7 @@ void WebViewImpl::setSelectionColors(uns
                                      unsigned activeForegroundColor,
                                      unsigned inactiveBackgroundColor,
                                      unsigned inactiveForegroundColor) {
-#if OS(LINUX) || OS(FREEBSD)
+#if OS(LINUX) || OS(BSD)
     RenderThemeChromiumLinux::setSelectionColors(activeBackgroundColor,
                                                  activeForegroundColor,
                                                  inactiveBackgroundColor,
@@ -2141,7 +2141,7 @@ bool WebViewImpl::navigationPolicyFromMo
                                                  bool alt, bool meta,
                                                  WebNavigationPolicy* policy)
 {
-#if OS(WINDOWS) || OS(LINUX) || OS(FREEBSD) || OS(SOLARIS)
+#if OS(WINDOWS) || OS(LINUX) || OS(BSD) || OS(SOLARIS)
     const bool newTabModifier = (button == 1) || ctrl;
 #elif OS(DARWIN)
     const bool newTabModifier = (button == 1) || meta;

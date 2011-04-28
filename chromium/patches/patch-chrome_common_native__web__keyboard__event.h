$NetBSD: patch-chrome_common_native__web__keyboard__event.h,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/common/native_web_keyboard_event.h.orig	2011-04-13 08:01:58.000000000 +0000
+++ chrome/common/native_web_keyboard_event.h
@@ -60,7 +60,7 @@ struct NativeWebKeyboardEvent : public W
   // Currently, it's only used by Linux and Mac ports.
   bool skip_in_browser;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // True if the key event matches an edit command. In order to ensure the edit
   // command always work in web page, the browser should not pre-handle this key
   // event as a reserved accelerator. See http://crbug.com/54573

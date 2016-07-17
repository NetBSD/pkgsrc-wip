$NetBSD$

--- ui/events/keycodes/dom/keycode_converter.cc.orig	2016-06-24 01:02:52.000000000 +0000
+++ ui/events/keycodes/dom/keycode_converter.cc
@@ -19,7 +19,7 @@ namespace {
 // and DOM Level 3 |code| strings.
 #if defined(OS_WIN)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, win, code}
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, xkb, code}
 #elif defined(OS_MACOSX)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, mac, code}

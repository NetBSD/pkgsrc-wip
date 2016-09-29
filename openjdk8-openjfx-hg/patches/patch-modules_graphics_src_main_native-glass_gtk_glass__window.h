$NetBSD$

WindowContext is a class, not a struct.

--- modules/graphics/src/main/native-glass/gtk/glass_window.h.orig	2016-03-04 00:57:09.000000000 +0000
+++ modules/graphics/src/main/native-glass/gtk/glass_window.h
@@ -365,7 +365,7 @@ private:
 class WindowContextTop: public WindowContextBase {
     jlong screen;
     WindowFrameType frame_type;
-    struct WindowContext *owner;
+    WindowContext *owner;
     WindowGeometry geometry;
     int stale_config_notifications;
     struct _Resizable{// we can't use set/get gtk_window_resizable function

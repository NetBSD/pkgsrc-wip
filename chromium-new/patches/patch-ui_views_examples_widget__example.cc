$NetBSD$

--- ui/views/examples/widget_example.cc.orig	2016-11-10 20:02:30.000000000 +0000
+++ ui/views/examples/widget_example.cc
@@ -77,7 +77,7 @@ void WidgetExample::CreateExampleView(Vi
   BuildButton(container, "Popup widget", POPUP);
   BuildButton(container, "Dialog widget", DIALOG);
   BuildButton(container, "Modal Dialog", MODAL_DIALOG);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   BuildButton(container, "Child widget", CHILD);
 #endif

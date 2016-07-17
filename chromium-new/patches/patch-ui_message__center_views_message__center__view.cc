$NetBSD$

--- ui/message_center/views/message_center_view.cc.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/message_center/views/message_center_view.cc
@@ -44,7 +44,7 @@ namespace message_center {
 namespace {
 
 const SkColor kNoNotificationsTextColor = SkColorSetRGB(0xb4, 0xb4, 0xb4);
-#if defined(OS_LINUX) && defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(OS_CHROMEOS)
 const SkColor kTransparentColor = SkColorSetARGB(0, 0, 0, 0);
 #endif
 
@@ -82,7 +82,7 @@ NoNotificationMessageView::NoNotificatio
   label_->SetEnabledColor(kNoNotificationsTextColor);
   // Set transparent background to ensure that subpixel rendering
   // is disabled. See crbug.com/169056
-#if defined(OS_LINUX) && defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(OS_CHROMEOS)
   label_->SetBackgroundColor(kTransparentColor);
 #endif
   AddChildView(label_);

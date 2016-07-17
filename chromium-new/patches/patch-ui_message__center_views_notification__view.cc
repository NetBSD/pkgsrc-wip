$NetBSD$

--- ui/message_center/views/notification_view.cc.orig	2016-06-24 01:02:53.000000000 +0000
+++ ui/message_center/views/notification_view.cc
@@ -173,7 +173,7 @@ NotificationView* NotificationView::Crea
   NotificationView* notification_view =
       new NotificationView(controller, notification);
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Don't create shadows for notification toasts on linux wih aura.
   if (top_level)
     return notification_view;

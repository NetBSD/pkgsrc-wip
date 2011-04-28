$NetBSD: patch-chrome_browser_task__manager_task__manager__resource__providers.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/task_manager/task_manager_resource_providers.cc.orig	2011-04-13 08:01:40.000000000 +0000
+++ chrome/browser/task_manager/task_manager_resource_providers.cc
@@ -1240,7 +1240,7 @@ TaskManagerBrowserProcessResource::TaskM
       default_icon_ = IconUtil::CreateSkBitmapFromHICON(icon, icon_size);
     }
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!default_icon_) {
     ResourceBundle& rb = ResourceBundle::GetSharedInstance();
     default_icon_ = rb.GetBitmapNamed(IDR_PRODUCT_LOGO_16);

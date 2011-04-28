$NetBSD: patch-chrome_browser_tab__contents_tab__contents.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/tab_contents/tab_contents.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/tab_contents/tab_contents.cc
@@ -443,7 +443,7 @@ TabContents::TabContents(Profile* profil
                  NotificationService::AllSources());
   registrar_.Add(this, NotificationType::RENDER_WIDGET_HOST_DESTROYED,
                  NotificationService::AllSources());
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
   registrar_.Add(this, NotificationType::BROWSER_THEME_CHANGED,
                  NotificationService::AllSources());
 #endif
@@ -3264,7 +3264,7 @@ void TabContents::Observe(NotificationTy
       break;
     }
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
     case NotificationType::BROWSER_THEME_CHANGED: {
       renderer_preferences_util::UpdateFromSystemSettings(
           &renderer_preferences_, profile());

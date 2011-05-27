$NetBSD: patch-content_browser_tab__contents_tab__contents.cc,v 1.1 2011/05/27 13:23:09 rxg Exp $

--- content/browser/tab_contents/tab_contents.cc.orig	2011-05-24 08:01:07.000000000 +0000
+++ content/browser/tab_contents/tab_contents.cc
@@ -301,7 +301,7 @@ TabContents::TabContents(Profile* profil
 
   registrar_.Add(this, NotificationType::RENDER_WIDGET_HOST_DESTROYED,
                  NotificationService::AllSources());
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
   registrar_.Add(this, NotificationType::BROWSER_THEME_CHANGED,
                  NotificationService::AllSources());
 #endif
@@ -2723,7 +2723,7 @@ void TabContents::Observe(NotificationTy
       break;
     }
 
-#if defined(OS_LINUX)
+#if defined(TOOLKIT_GTK)
     case NotificationType::BROWSER_THEME_CHANGED: {
       renderer_preferences_util::UpdateFromSystemSettings(
           &renderer_preferences_, profile());

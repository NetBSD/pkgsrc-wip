$NetBSD: patch-chrome_browser_ui_views_create__application__shortcut__view.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/browser/ui/views/create_application_shortcut_view.cc.orig	2011-04-13 08:01:42.000000000 +0000
+++ chrome/browser/ui/views/create_application_shortcut_view.cc
@@ -256,7 +256,7 @@ void CreateApplicationShortcutView::Init
         UTF16ToWide(l10n_util::GetStringUTF16(
             IDS_CREATE_SHORTCUTS_QUICK_LAUNCH_BAR_CHKBOX)),
       profile_->GetPrefs()->GetBoolean(prefs::kWebAppCreateInQuickLaunchBar));
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   menu_check_box_ = AddCheckbox(
       UTF16ToWide(l10n_util::GetStringUTF16(IDS_CREATE_SHORTCUTS_MENU_CHKBOX)),
       profile_->GetPrefs()->GetBoolean(prefs::kWebAppCreateInAppsMenu));

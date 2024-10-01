$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc.orig	2024-09-24 20:49:20.846191600 +0000
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc
@@ -56,7 +56,7 @@ namespace {
 
 const int kModalDialogWidth = 448;
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 const int kManagedUserNoticeConfirmationDialogWidth = 512;
 const int kManagedUserNoticeConfirmationDialogHeight = 576;
 const int kManagedUserNoticeConfirmationUpdatedDialogWidth = 900;
@@ -174,7 +174,7 @@ SigninViewControllerDelegateViews::Creat
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // static
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateManagedUserNoticeConfirmationWebView(
@@ -336,7 +336,7 @@ SigninViewControllerDelegateViews::Signi
   SetButtons(ui::DIALOG_BUTTON_NONE);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // On the local profile creation dialog, cancelling the dialog (for instance
   // through the VKEY_ESCAPE accelerator) should delete the profile.
   if (delete_profile_on_cancel) {
@@ -425,7 +425,7 @@ void SigninViewControllerDelegateViews::
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 void SigninViewControllerDelegateViews::DeleteProfileOnCancel() {
   ProfileAttributesEntry* entry =
       g_browser_process->profile_manager()
@@ -500,7 +500,7 @@ SigninViewControllerDelegate::CreateProf
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT) || BUILDFLAG(IS_CHROMEOS_LACROS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(

$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc.orig	2025-07-21 19:32:31.000000000 +0000
+++ chrome/browser/ui/views/profiles/signin_view_controller_delegate_views.cc
@@ -62,14 +62,14 @@
 #include "chrome/browser/ui/webui/signin/signout_confirmation/signout_confirmation_ui.h"
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/signin/history_sync_optin/history_sync_optin_ui.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 namespace {
 
 const int kModalDialogWidth = 448;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const int kManagedUserNoticeConfirmationDialogWidth = 512;
 const int kManagedUserNoticeConfirmationDialogHeight = 576;
 const int kManagedUserNoticeConfirmationUpdatedDialogWidth = 780;
@@ -138,7 +138,7 @@ SigninViewControllerDelegateViews::Creat
       kSyncConfirmationDialogWidth, InitializeSigninWebDialogUI(true));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateHistorySyncOptInWebView(
     Browser* browser) {
@@ -224,7 +224,7 @@ SigninViewControllerDelegateViews::Creat
 }
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 std::unique_ptr<views::WebView>
 SigninViewControllerDelegateViews::CreateManagedUserNoticeConfirmationWebView(
@@ -409,7 +409,7 @@ SigninViewControllerDelegateViews::Signi
 
   SetButtons(static_cast<int>(ui::mojom::DialogButton::kNone));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On the local profile creation dialog, cancelling the dialog (for instance
   // through the VKEY_ESCAPE accelerator) should delete the profile.
   if (delete_profile_on_cancel) {
@@ -501,7 +501,7 @@ void SigninViewControllerDelegateViews::
   content_view_->RequestFocus();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SigninViewControllerDelegateViews::DeleteProfileOnCancel() {
   ProfileAttributesEntry* entry =
       g_browser_process->profile_manager()
@@ -541,7 +541,7 @@ SigninViewControllerDelegate::CreateSync
       /*animate_on_resize=*/true);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateSyncHistoryOptInDelegate(Browser* browser) {
@@ -595,7 +595,7 @@ SigninViewControllerDelegate::CreateSign
 }
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // static
 SigninViewControllerDelegate*
 SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(

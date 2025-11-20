$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc.orig	2025-11-14 20:31:45.000000000 +0000
+++ chrome/browser/ui/views/data_sharing/collaboration_controller_delegate_desktop.cc
@@ -91,7 +91,7 @@ DialogText GetPromptDialogTextFromStatus
       break;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           syncer::kReplaceSyncPromosWithSignInPromos) &&
       status.signin_status != collaboration::SigninStatus::kSigninDisabled) {
@@ -404,7 +404,7 @@ void CollaborationControllerDelegateDesk
       chrome::ShowBrowserModal(browser_, std::move(dialog_model));
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void CollaborationControllerDelegateDesktop::
     MaybeShowSignInUiForHistorySyncOptin() {
   collaboration::ServiceStatus status = GetServiceStatus();
@@ -516,7 +516,7 @@ void CollaborationControllerDelegateDesk
                 .SetLabel(dialog_text.ok_button_text)
                 .SetEnabled(true));
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     AccountInfo account_for_promo = signin_ui_util::GetSingleAccountForPromos(
         IdentityManagerFactory::GetForProfile(browser_->profile()));
 
@@ -569,7 +569,7 @@ void CollaborationControllerDelegateDesk
         .Run(CollaborationControllerDelegate::Outcome::kSuccess);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           syncer::kReplaceSyncPromosWithSignInPromos)) {
     MaybeShowSignInUiForHistorySyncOptin();

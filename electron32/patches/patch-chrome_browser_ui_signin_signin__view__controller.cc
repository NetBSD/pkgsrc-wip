$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2024-10-18 12:34:03.244333000 +0000
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -492,7 +492,7 @@ void SigninViewController::ShowModalMana
     signin::SigninChoiceCallbackVariant process_user_choice_callback,
     base::OnceClosure done_callback) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS_LACROS)
+    BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(

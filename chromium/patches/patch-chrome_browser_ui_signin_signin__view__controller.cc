$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/signin/signin_view_controller.cc.orig	2025-05-30 19:50:32.000000000 +0000
+++ chrome/browser/ui/signin/signin_view_controller.cc
@@ -444,7 +444,7 @@ void SigninViewController::ShowModalSync
 void SigninViewController::ShowModalManagedUserNoticeDialog(
     std::unique_ptr<signin::EnterpriseProfileCreationDialogParams>
         create_param) {
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CloseModalSignin();
   dialog_ = std::make_unique<SigninModalDialogImpl>(
       SigninViewControllerDelegate::CreateManagedUserNoticeDelegate(

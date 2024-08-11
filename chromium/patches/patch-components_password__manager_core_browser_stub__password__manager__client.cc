$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/stub_password_manager_client.cc.orig	2024-07-24 02:44:34.616585700 +0000
+++ components/password_manager/core/browser/stub_password_manager_client.cc
@@ -175,7 +175,7 @@ version_info::Channel StubPasswordManage
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 std::unique_ptr<
     password_manager::PasswordCrossDomainConfirmationPopupController>
 StubPasswordManagerClient::ShowCrossDomainConfirmationPopup(

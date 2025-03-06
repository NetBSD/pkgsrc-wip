$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/stub_password_manager_client.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ components/password_manager/core/browser/stub_password_manager_client.cc
@@ -199,7 +199,7 @@ version_info::Channel StubPasswordManage
 }
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 void StubPasswordManagerClient::OpenPasswordDetailsBubble(
     const password_manager::PasswordForm& form) {}
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) ||

$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_browser_utils.cc.orig	2024-10-26 06:59:59.267156400 +0000
+++ chrome/browser/supervised_user/supervised_user_browser_utils.cc
@@ -42,7 +42,7 @@
 #include "components/user_manager/user_type.h"
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
 #include "chromeos/startup/browser_params_proxy.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/supervised_user/supervised_user_verification_controller_client.h"
 #include "chrome/browser/supervised_user/supervised_user_verification_page.h"
 #endif
@@ -165,7 +165,7 @@ void AssertChildStatusOfTheUser(Profile*
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 std::string CreateReauthenticationInterstitial(
     content::NavigationHandle& navigation_handle,
     SupervisedUserVerificationPage::VerificationPurpose verification_purpose) {

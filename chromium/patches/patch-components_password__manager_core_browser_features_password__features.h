$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/password_manager/core/browser/features/password_features.h.orig	2026-08-05 20:17:42.000000000 +0000
+++ components/password_manager/core/browser/features/password_features.h
@@ -194,7 +194,7 @@ BASE_DECLARE_FEATURE(kPreventAPCOnFedera
 // Prevents password manager from showing save/update UI on federated login.
 BASE_DECLARE_FEATURE(kPreventPasswordManagerOnFederatedLogin);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables "Needs access to keychain, restart chrome" bubble and banner.
 BASE_DECLARE_FEATURE(kRestartToGainAccessToKeychain);
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)

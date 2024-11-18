$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/webauthn/gpm_user_verification_policy.cc.orig	2024-11-14 01:04:05.059568600 +0000
+++ chrome/browser/webauthn/gpm_user_verification_policy.cc
@@ -17,7 +17,7 @@ bool GpmWillDoUserVerification(device::U
       return platform_has_biometrics;
 #elif BUILDFLAG(IS_MAC)
       return platform_has_biometrics;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       return false;
 #else
       // This default is for unit tests.

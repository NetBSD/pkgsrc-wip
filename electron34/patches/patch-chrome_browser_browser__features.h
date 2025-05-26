$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/browser_features.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/browser_features.h
@@ -37,7 +37,7 @@ BASE_DECLARE_FEATURE(kBookmarkTriggerFor
 BASE_DECLARE_FEATURE(kCertificateTransparencyAskBeforeEnabling);
 BASE_DECLARE_FEATURE(kCertVerificationNetworkTime);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDbusSecretPortal);
 #endif
 
@@ -111,7 +111,7 @@ BASE_DECLARE_FEATURE(kRestartNetworkServ
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlocked);
 BASE_DECLARE_FEATURE(kSandboxExternalProtocolBlockedWarning);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kSecretPortalKeyProviderUseForEncryption);
 #endif
 

$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/signin/public/base/signin_switches.h.orig	2025-09-29 17:05:47.000000000 +0000
+++ components/signin/public/base/signin_switches.h
@@ -67,7 +67,7 @@ COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSupportWebSigninAddSession);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kEnableHistorySyncOptin);
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
@@ -235,7 +235,7 @@ BASE_DECLARE_FEATURE(kSyncEnableBookmark
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 bool IsExtensionsExplicitBrowserSigninEnabled();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Uses the Material Next theme for the signin promo.
 COMPONENT_EXPORT(SIGNIN_SWITCHES)
 BASE_DECLARE_FEATURE(kSignInPromoMaterialNextUI);

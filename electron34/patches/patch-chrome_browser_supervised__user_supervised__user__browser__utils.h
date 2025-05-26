$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/supervised_user/supervised_user_browser_utils.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_browser_utils.h
@@ -52,7 +52,7 @@ std::string GetAccountGivenName(Profile&
 // of the user.
 void AssertChildStatusOfTheUser(Profile* profile, bool is_child);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // Returns the html content of the reauthentication interstitial for blocked
 // sites. This interstitial is associated with the given NavigationHandle.
 std::string CreateReauthenticationInterstitialForBlockedSites(

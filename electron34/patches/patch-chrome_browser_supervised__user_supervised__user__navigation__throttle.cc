$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/supervised_user/supervised_user_navigation_throttle.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/supervised_user/supervised_user_navigation_throttle.cc
@@ -215,7 +215,7 @@ void SupervisedUserNavigationThrottle::O
     case kCancelWithInterstitial: {
       CHECK(navigation_handle());
 // LINT.IfChange(cancel_with_interstitial)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       if (supervised_user::ShouldShowReAuthInterstitial(*navigation_handle(),
                                                         is_main_frame)) {
         // Show the re-authentication interstitial if the user signed out of
@@ -246,7 +246,7 @@ void SupervisedUserNavigationThrottle::O
 }
 
 namespace supervised_user {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 bool ShouldShowReAuthInterstitial(content::NavigationHandle& navigation_handle,
                                   bool is_main_frame) {

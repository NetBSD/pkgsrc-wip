$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/supervised_user/supervised_user_navigation_throttle.cc.orig	2024-09-24 20:49:19.854104500 +0000
+++ chrome/browser/supervised_user/supervised_user_navigation_throttle.cc
@@ -212,7 +212,7 @@ void SupervisedUserNavigationThrottle::O
       Profile* profile = Profile::FromBrowserContext(
           navigation_handle()->GetWebContents()->GetBrowserContext());
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       if (base::FeatureList::IsEnabled(
               supervised_user::
                   kForceSupervisedUserReauthenticationForBlockedSites) &&

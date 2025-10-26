$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/components/supervised_user/core/common/pref_names.h.orig	2025-09-25 11:10:42.000000000 +0000
+++ src/3rdparty/chromium/components/supervised_user/core/common/pref_names.h
@@ -137,7 +137,7 @@ inline constexpr char kFirstTimeIntersti
     "profile.managed.banner_state";
 
 #if BUILDFLAG(ENABLE_EXTENSIONS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // An integer pref that stores the current state of the local extension
 // parent approval migration when the feature
 // `kEnableSupervisedUserSkipParentApprovalToInstallExtensions` becomes enabled.

$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/supervised_user/core/common/features.cc.orig	2025-03-31 15:23:48.000000000 +0000
+++ components/supervised_user/core/common/features.cc
@@ -36,7 +36,7 @@ BASE_FEATURE(kAllowSubframeLocalWebAppro
 #endif
 
 #if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const int kLocalWebApprovalBottomSheetLoadTimeoutDefaultValueMs = 5000;
 
 const base::FeatureParam<int> kLocalWebApprovalBottomSheetLoadTimeoutMs{
@@ -83,7 +83,7 @@ BASE_FEATURE(kUpdatedSupervisedUserExten
              "UpdatedSupervisedUserExtensionApprovalStrings",
              base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableExtensionsPermissionsForSupervisedUsersOnDesktop,
              "EnableExtensionsPermissionsForSupervisedUsersOnDesktop",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -98,7 +98,7 @@ bool IsSupervisedUserSkipParentApprovalT
 #if BUILDFLAG(IS_CHROMEOS)
   return base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   bool skipParentApprovalEnabled = base::FeatureList::IsEnabled(
       kEnableSupervisedUserSkipParentApprovalToInstallExtensions);
   bool permissionExtensionsForSupervisedUsersEnabled =
@@ -115,7 +115,7 @@ bool IsSupervisedUserSkipParentApprovalT
 }
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kCustomProfileStringsForSupervisedUsers,
              "CustomProfileStringsForSupervisedUsers",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -127,13 +127,13 @@ BASE_FEATURE(kShowKiteForSupervisedUsers
 
 BASE_FEATURE(kForceSafeSearchForUnauthenticatedSupervisedUsers,
              "ForceSafeSearchForUnauthenticatedSupervisedUsers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableSupervisedUserVersionSignOutDialog,
              "EnableSupervisedUserVersionSignOutDialog",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -155,7 +155,7 @@ BASE_FEATURE(kExemptYouTubeInfrastructur
 // platform #defines.
 BASE_FEATURE(kUncredentialedFilteringFallbackForSupervisedUsers,
              "UncredentialedFilteringFallbackForSupervisedUsers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);

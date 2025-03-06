$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/util/managed_browser_utils.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ chrome/browser/enterprise/util/managed_browser_utils.cc
@@ -222,7 +222,7 @@ void SetUserAcceptedAccountManagement(Pr
           .GetProfileAttributesWithPath(profile->GetPath());
   if (entry) {
     entry->SetUserAcceptedAccountManagement(accepted);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     entry->SetEnterpriseProfileLabel(GetEnterpriseLabel(profile));
 #endif
   }

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/managed_ui.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/managed_ui.cc
@@ -439,7 +439,7 @@ std::optional<std::string> GetDeviceMana
       g_browser_process->platform_part()->browser_policy_connector_ash();
   return connector->GetEnterpriseDomainManager();
 #else
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kEnterpriseManagementDisclaimerUsesCustomLabel)) {
     std::string custom_management_label =
@@ -476,7 +476,7 @@ std::optional<std::string> GetAccountMan
                policy::EnterpriseManagementAuthority::CLOUD))
     return std::nullopt;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kEnterpriseManagementDisclaimerUsesCustomLabel)) {
     std::string custom_management_label =

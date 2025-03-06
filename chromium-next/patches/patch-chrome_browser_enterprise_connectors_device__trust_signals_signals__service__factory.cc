$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc
@@ -24,7 +24,7 @@
 #include "chrome/browser/enterprise/connectors/connectors_service.h"
 #endif  // BUILDFLAG(ENTERPRISE_CLOUD_CONTENT_ANALYSIS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/check.h"
 #include "chrome/browser/enterprise/connectors/device_trust/signals/decorators/browser/browser_signals_decorator.h"
 #include "chrome/browser/enterprise/core/dependency_factory_impl.h"
@@ -64,7 +64,7 @@ std::unique_ptr<SignalsService> CreateSi
           profile, ConnectorsServiceFactory::GetForBrowserContext(profile))));
 #endif  // BUILDFLAG(ENTERPRISE_CLOUD_CONTENT_ANALYSIS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
   policy::CloudPolicyManager* browser_policy_manager = nullptr;
   if (management_service->HasManagementAuthority(

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/enterprise/connectors/device_trust/signals/signals_service_factory.cc
@@ -21,7 +21,7 @@
 #include "chrome/browser/profiles/profile.h"
 #include "components/policy/core/common/management/management_service.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/check.h"
 #include "chrome/browser/enterprise/connectors/device_trust/signals/decorators/browser/browser_signals_decorator.h"
 #include "chrome/browser/enterprise/core/dependency_factory_impl.h"
@@ -58,7 +58,7 @@ std::unique_ptr<SignalsService> CreateSi
       enterprise_signals::ContextInfoFetcher::CreateInstance(
           profile, ConnectorsServiceFactory::GetForBrowserContext(profile))));
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 
   policy::CloudPolicyManager* browser_policy_manager = nullptr;
   if (management_service->HasManagementAuthority(

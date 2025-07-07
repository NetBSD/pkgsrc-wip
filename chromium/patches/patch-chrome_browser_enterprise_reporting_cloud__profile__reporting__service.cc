$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ chrome/browser/enterprise/reporting/cloud_profile_reporting_service.cc
@@ -34,7 +34,7 @@
 #include "extensions/buildflags/buildflags.h"
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/signals/signals_aggregator_factory.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -113,7 +113,7 @@ void CloudProfileReportingService::Creat
   params.profile_request_generator =
       std::make_unique<ChromeProfileRequestGenerator>(
           profile_->GetPath(), &delegate_factory,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
           enterprise_signals::SignalsAggregatorFactory::GetForProfile(
               profile_));
 #else

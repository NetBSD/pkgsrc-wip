$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc
@@ -18,7 +18,7 @@
 #include "net/base/url_util.h"
 #include "third_party/abseil-cpp/absl/types/variant.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/analysis/local_binary_upload_service_factory.h"
 #endif
 
@@ -437,7 +437,7 @@ BinaryUploadService* BinaryUploadService
     Profile* profile,
     const enterprise_connectors::AnalysisSettings& settings) {
   // Local content analysis is supported only on desktop platforms.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (settings.cloud_or_local_settings.is_cloud_analysis()) {
     return CloudBinaryUploadServiceFactory::GetForProfile(profile);
   } else {

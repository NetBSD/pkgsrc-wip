$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc.orig	2025-02-25 19:55:16.000000000 +0000
+++ chrome/browser/safe_browsing/cloud_content_scanning/binary_upload_service.cc
@@ -20,7 +20,7 @@
 #include "net/base/url_util.h"
 #include "third_party/abseil-cpp/absl/types/variant.h"
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/analysis/local_binary_upload_service_factory.h"
 #endif
 

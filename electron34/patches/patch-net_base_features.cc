$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- net/base/features.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ net/base/features.cc
@@ -26,7 +26,7 @@ BASE_FEATURE(kCapReferrerToOriginOnCross
 BASE_FEATURE(kAsyncDns,
              "AsyncDns",
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -528,7 +528,12 @@ BASE_FEATURE(kSpdyHeadersToHttpResponseU
              "SpdyHeadersToHttpResponseUseBuilder",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
+#if BUILDFLAG(IS_OPENBSD) || BUILDFLAG(IS_NETBSD)
+// No IP_RECVTOS support
 BASE_FEATURE(kReportEcn, "ReportEcn", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
+BASE_FEATURE(kReportEcn, "ReportEcn", base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 BASE_FEATURE(kUseNewAlpsCodepointHttp2,
              "UseNewAlpsCodepointHttp2",

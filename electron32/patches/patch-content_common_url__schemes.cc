$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/common/url_schemes.cc.orig	2024-10-18 12:34:14.246470000 +0000
+++ content/common/url_schemes.cc
@@ -98,6 +98,14 @@ void RegisterContentSchemes(bool should_
   for (auto& scheme : schemes.empty_document_schemes)
     url::AddEmptyDocumentScheme(scheme.c_str());
 
+  for (auto& scheme : schemes.code_cache_schemes) {
+    CHECK_NE(scheme, kChromeUIScheme);
+    CHECK_NE(scheme, kChromeUIUntrustedScheme);
+    CHECK_NE(scheme, url::kHttpScheme);
+    CHECK_NE(scheme, url::kHttpsScheme);
+    url::AddCodeCacheScheme(scheme.c_str());
+  }
+
 #if BUILDFLAG(IS_ANDROID)
   if (schemes.allow_non_standard_schemes_in_origins)
     url::EnableNonStandardSchemesForAndroidWebView();

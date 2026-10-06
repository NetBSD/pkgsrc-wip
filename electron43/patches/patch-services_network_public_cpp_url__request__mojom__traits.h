$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/public/cpp/url_request_mojom_traits.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ services/network/public/cpp/url_request_mojom_traits.h
@@ -76,6 +76,10 @@ struct COMPONENT_EXPORT(NETWORK_CPP_BASE
       const network::ResourceRequest::TrustedParams& trusted_params) {
     return trusted_params.include_request_cookies_with_response;
   }
+  static bool report_raw_headers(
+      const network::ResourceRequest::TrustedParams& trusted_params) {
+    return trusted_params.report_raw_headers;
+  }
   static mojo::PendingRemote<network::mojom::CookieAccessObserver>
   cookie_observer(
       const network::ResourceRequest::TrustedParams& trusted_params) {

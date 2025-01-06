$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/public/cpp/url_request_mojom_traits.h.orig	2024-10-18 12:34:32.093719700 +0000
+++ services/network/public/cpp/url_request_mojom_traits.h
@@ -77,6 +77,10 @@ struct COMPONENT_EXPORT(NETWORK_CPP_BASE
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

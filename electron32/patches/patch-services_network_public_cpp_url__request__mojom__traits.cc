$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/public/cpp/url_request_mojom_traits.cc.orig	2024-10-18 12:34:32.093719700 +0000
+++ services/network/public/cpp/url_request_mojom_traits.cc
@@ -96,6 +96,7 @@ bool StructTraits<network::mojom::Truste
   out->allow_cookies_from_browser = data.allow_cookies_from_browser();
   out->include_request_cookies_with_response =
       data.include_request_cookies_with_response();
+  out->report_raw_headers = data.report_raw_headers();
   out->cookie_observer = data.TakeCookieObserver<
       mojo::PendingRemote<network::mojom::CookieAccessObserver>>();
   out->trust_token_observer = data.TakeTrustTokenObserver<

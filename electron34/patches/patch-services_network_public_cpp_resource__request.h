$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/public/cpp/resource_request.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ services/network/public/cpp/resource_request.h
@@ -74,6 +74,7 @@ struct COMPONENT_EXPORT(NETWORK_CPP_BASE
     bool has_user_activation = false;
     bool allow_cookies_from_browser = false;
     bool include_request_cookies_with_response = false;
+    bool report_raw_headers = false;
     mojo::PendingRemote<mojom::CookieAccessObserver> cookie_observer;
     mojo::PendingRemote<mojom::TrustTokenAccessObserver> trust_token_observer;
     mojo::PendingRemote<mojom::URLLoaderNetworkServiceObserver>

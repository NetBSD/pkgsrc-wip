$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/public/cpp/resource_request.h.orig	2024-10-18 12:34:32.089721700 +0000
+++ services/network/public/cpp/resource_request.h
@@ -73,6 +73,7 @@ struct COMPONENT_EXPORT(NETWORK_CPP_BASE
     bool has_user_activation = false;
     bool allow_cookies_from_browser = false;
     bool include_request_cookies_with_response = false;
+    bool report_raw_headers = false;
     mojo::PendingRemote<mojom::CookieAccessObserver> cookie_observer;
     mojo::PendingRemote<mojom::TrustTokenAccessObserver> trust_token_observer;
     mojo::PendingRemote<mojom::URLLoaderNetworkServiceObserver>

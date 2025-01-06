$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/public/cpp/resource_request.cc.orig	2024-10-18 12:34:32.089721700 +0000
+++ services/network/public/cpp/resource_request.cc
@@ -155,6 +155,7 @@ ResourceRequest::TrustedParams& Resource
   allow_cookies_from_browser = other.allow_cookies_from_browser;
   include_request_cookies_with_response =
       other.include_request_cookies_with_response;
+  report_raw_headers = other.report_raw_headers;
   cookie_observer =
       Clone(&const_cast<mojo::PendingRemote<mojom::CookieAccessObserver>&>(
           other.cookie_observer));
@@ -185,6 +186,7 @@ bool ResourceRequest::TrustedParams::Equ
     const TrustedParams& other) const {
   return isolation_info.IsEqualForTesting(other.isolation_info) &&
          disable_secure_dns == other.disable_secure_dns &&
+         report_raw_headers == other.report_raw_headers &&
          has_user_activation == other.has_user_activation &&
          allow_cookies_from_browser == other.allow_cookies_from_browser &&
          include_request_cookies_with_response ==

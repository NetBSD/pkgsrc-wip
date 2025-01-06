$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/url_loader.h.orig	2024-10-18 12:34:32.113710400 +0000
+++ services/network/url_loader.h
@@ -670,6 +670,8 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
   std::unique_ptr<ResourceScheduler::ScheduledResourceRequest>
       resource_scheduler_request_handle_;
 
+  // Whether client requested raw headers.
+  bool report_raw_headers_ = false;
   bool enable_reporting_raw_headers_ = false;
   bool seen_raw_request_headers_ = false;
   scoped_refptr<const net::HttpResponseHeaders> raw_response_headers_;

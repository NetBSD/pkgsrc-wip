$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- services/network/url_loader.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ services/network/url_loader.h
@@ -708,6 +708,8 @@ class COMPONENT_EXPORT(NETWORK_SERVICE) 
   std::unique_ptr<ResourceScheduler::ScheduledResourceRequest>
       resource_scheduler_request_handle_;
 
+  // Whether client requested raw headers.
+  bool report_raw_headers_ = false;
   bool enable_reporting_raw_headers_ = false;
   bool seen_raw_request_headers_ = false;
   // Used for metrics.

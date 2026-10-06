$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/web/web_view.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/public/web/web_view.h
@@ -371,6 +371,7 @@ class BLINK_EXPORT WebView {
   // Scheduling -----------------------------------------------------------
 
   virtual PageScheduler* Scheduler() const = 0;
+  virtual void SetSchedulerThrottling(bool allowed) {}
 
   // Visibility -----------------------------------------------------------
 

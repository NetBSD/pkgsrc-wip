$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/web/web_view.h.orig	2024-10-18 12:34:34.708505000 +0000
+++ third_party/blink/public/web/web_view.h
@@ -362,6 +362,7 @@ class BLINK_EXPORT WebView {
   // Scheduling -----------------------------------------------------------
 
   virtual PageScheduler* Scheduler() const = 0;
+  virtual void SetSchedulerThrottling(bool allowed) {}
 
   // Visibility -----------------------------------------------------------
 

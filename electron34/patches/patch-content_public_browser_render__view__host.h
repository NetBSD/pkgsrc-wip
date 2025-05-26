$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/public/browser/render_view_host.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/public/browser/render_view_host.h
@@ -75,6 +75,9 @@ class CONTENT_EXPORT RenderViewHost {
   virtual void WriteIntoTrace(
       perfetto::TracedProto<TraceProto> context) const = 0;
 
+  // Disable/Enable scheduler throttling.
+  virtual void SetSchedulerThrottling(bool allowed) {}
+
  private:
   // This interface should only be implemented inside content.
   friend class RenderViewHostImpl;

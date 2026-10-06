$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/exported/web_view_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/exported/web_view_impl.h
@@ -448,6 +448,7 @@ class CORE_EXPORT WebViewImpl final : pu
   LocalDOMWindow* PagePopupWindow() const;
 
   PageScheduler* Scheduler() const override;
+  void SetSchedulerThrottling(bool allowed) override;
   void SetVisibilityState(mojom::blink::PageVisibilityState visibility_state,
                           bool is_initial_state) override;
   mojom::blink::PageVisibilityState GetVisibilityState() override;
@@ -936,6 +937,8 @@ class CORE_EXPORT WebViewImpl final : pu
   // If true, we send IPC messages when |preferred_size_| changes.
   bool send_preferred_size_changes_ = false;
 
+  bool scheduler_throttling_allowed_ = true;
+
   // Whether the preferred size may have changed and |UpdatePreferredSize| needs
   // to be called.
   bool needs_preferred_size_update_ = true;

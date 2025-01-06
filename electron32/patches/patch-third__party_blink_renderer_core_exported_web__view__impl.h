$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/exported/web_view_impl.h.orig	2024-10-18 12:34:35.388191500 +0000
+++ third_party/blink/renderer/core/exported/web_view_impl.h
@@ -449,6 +449,7 @@ class CORE_EXPORT WebViewImpl final : pu
   LocalDOMWindow* PagePopupWindow() const;
 
   PageScheduler* Scheduler() const override;
+  void SetSchedulerThrottling(bool allowed) override;
   void SetVisibilityState(mojom::blink::PageVisibilityState visibility_state,
                           bool is_initial_state) override;
   mojom::blink::PageVisibilityState GetVisibilityState() override;
@@ -930,6 +931,8 @@ class CORE_EXPORT WebViewImpl final : pu
   // If true, we send IPC messages when |preferred_size_| changes.
   bool send_preferred_size_changes_ = false;
 
+  bool scheduler_throttling_allowed_ = true;
+
   // Whether the preferred size may have changed and |UpdatePreferredSize| needs
   // to be called.
   bool needs_preferred_size_update_ = true;

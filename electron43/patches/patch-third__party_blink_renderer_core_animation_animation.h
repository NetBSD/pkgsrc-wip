$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/animation/animation.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/animation/animation.h
@@ -393,6 +393,15 @@ class CORE_EXPORT Animation : public Eve
     start_time_ = start_time;
   }
 
+  enum NativePaintWorkletProperties {
+    kNoPaintWorklet = 0,
+    kBackgroundColorPaintWorklet = 1,
+    kClipPathPaintWorklet = 2
+  };
+
+  using NativePaintWorkletReasons = uint32_t;
+  NativePaintWorkletReasons GetNativePaintWorkletReasons();
+
  protected:
   DispatchEventResult DispatchEventInternal(Event&) override;
   void AddedEventListener(const AtomicString& event_type,
@@ -583,6 +592,13 @@ class CORE_EXPORT Animation : public Eve
 
   Member<Event> pending_remove_event_;
 
+  // Cache whether animation can potentially have native paint worklets.
+  // In the event of the keyframes changing, we need a new evaluation, of
+  // the composited status for native paint worklet eligible properties.
+  // A change in the playState can also necessitate a composited style update.
+  std::optional<NativePaintWorkletReasons> native_paint_worklet_reasons_;
+  std::optional<NativePaintWorkletReasons> prior_native_paint_worklet_reasons_;
+
   // TODO(crbug.com/960944): Consider reintroducing kPause and cleanup use of
   // mutually exclusive pending_play_ and pending_pause_ flags.
   enum class CompositorAction { kNone, kStart, kCancel };

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/webaudio/audio_worklet_handler.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/modules/webaudio/audio_worklet_handler.h
@@ -68,6 +68,10 @@ class AudioWorkletHandler final : public
       HashMap<String, scoped_refptr<AudioParamHandler>> param_handler_map,
       const AudioWorkletNodeOptions*);
 
+  // Used to avoid code duplication when using scoped objects that affect
+  // `Process`.
+  void ProcessInternal(uint32_t frames_to_process);
+
   String name_;
 
   double tail_time_ = std::numeric_limits<double>::infinity();
@@ -102,6 +106,9 @@ class AudioWorkletHandler final : public
   // when a processor stops invoking the user-defined `process()` callback.
   bool is_processor_active_ = true;
 
+  // Cached feature flag value
+  const bool allow_denormal_in_processing_;
+
   base::WeakPtrFactory<AudioWorkletHandler> weak_ptr_factory_{this};
 };
 

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/webaudio/audio_worklet_global_scope.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/modules/webaudio/audio_worklet_global_scope.cc
@@ -23,6 +23,7 @@
 #include "third_party/blink/renderer/modules/webaudio/audio_worklet_processor.h"
 #include "third_party/blink/renderer/modules/webaudio/audio_worklet_processor_definition.h"
 #include "third_party/blink/renderer/modules/webaudio/cross_thread_audio_worklet_processor_info.h"
+#include "third_party/blink/renderer/platform/audio/denormal_disabler.h"
 #include "third_party/blink/renderer/platform/bindings/callback_method_retriever.h"
 #include "third_party/blink/renderer/platform/heap/garbage_collected.h"
 
@@ -34,6 +35,9 @@ AudioWorkletGlobalScope::AudioWorkletGlo
     : WorkletGlobalScope(std::move(creation_params),
                          thread->GetWorkerReportingProxy(),
                          thread) {
+  // Disable denormals for performance.
+  DenormalModifier::DisableDenormals();
+
   // Audio is prone to jank introduced by e.g. the garbage collector. Workers
   // are generally put in a background mode (as they are non-visible). Audio is
   // an exception here, requiring low-latency behavior similar to any visible

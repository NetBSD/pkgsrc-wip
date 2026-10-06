$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/webaudio/audio_worklet_handler.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/modules/webaudio/audio_worklet_handler.cc
@@ -29,6 +29,7 @@
 #include "third_party/blink/renderer/modules/webaudio/cross_thread_audio_worklet_processor_info.h"
 #include "third_party/blink/renderer/platform/audio/audio_bus.h"
 #include "third_party/blink/renderer/platform/audio/audio_utilities.h"
+#include "third_party/blink/renderer/platform/audio/denormal_disabler.h"
 #include "third_party/blink/renderer/platform/bindings/exception_messages.h"
 #include "third_party/blink/renderer/platform/heap/persistent.h"
 #include "third_party/blink/renderer/platform/instrumentation/tracing/trace_event.h"
@@ -52,7 +53,9 @@ AudioWorkletHandler::AudioWorkletHandler
     const AudioWorkletNodeOptions* options)
     : AudioHandler(kNodeTypeAudioWorklet, node, sample_rate),
       name_(name),
-      param_handler_map_(param_handler_map) {
+      param_handler_map_(param_handler_map),
+      allow_denormal_in_processing_(base::FeatureList::IsEnabled(
+          features::kWebAudioAllowDenormalInProcessing)) {
   DCHECK(IsMainThread());
 
   for (const auto& param_name : param_handler_map_.Keys()) {
@@ -112,7 +115,7 @@ scoped_refptr<AudioWorkletHandler> Audio
                                                 param_handler_map, options));
 }
 
-void AudioWorkletHandler::Process(uint32_t frames_to_process) {
+void AudioWorkletHandler::ProcessInternal(uint32_t frames_to_process) {
   DCHECK(Context()->IsAudioThread());
 
   TRACE_EVENT0(TRACE_DISABLED_BY_DEFAULT("webaudio.audionode"),
@@ -175,6 +178,15 @@ void AudioWorkletHandler::Process(uint32
   }
 }
 
+void AudioWorkletHandler::Process(uint32_t frames_to_process) {
+  if (allow_denormal_in_processing_) {
+    DenormalEnabler denormal_enabler;
+    ProcessInternal(frames_to_process);
+  } else {
+    ProcessInternal(frames_to_process);
+  }
+}
+
 void AudioWorkletHandler::CheckNumberOfChannelsForInput(AudioNodeInput* input) {
   DCHECK(Context()->IsAudioThread());
   Context()->AssertGraphOwner();

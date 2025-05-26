$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/modules/webaudio/script_processor_handler.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/modules/webaudio/script_processor_handler.h
@@ -65,6 +65,7 @@ class ScriptProcessorHandler final : pub
                          uint32_t number_of_output_channels,
                          const HeapVector<Member<AudioBuffer>>& input_buffers,
                          const HeapVector<Member<AudioBuffer>>& output_buffers);
+
   double TailTime() const override;
   double LatencyTime() const override;
   bool RequiresTailProcessing() const final;

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/web_local_frame_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/frame/web_local_frame_impl.h
@@ -196,6 +196,7 @@ class CORE_EXPORT WebLocalFrameImpl fina
                             mojom::blink::EvaluationTiming,
                             mojom::blink::LoadEventBlockingOption,
                             WebScriptExecutionCallback,
+                            WebScriptExecutionCallbackUnmodified,
                             BackForwardCacheAware back_forward_cache_aware,
                             mojom::blink::WantResultOption,
                             mojom::blink::PromiseResultOption) override;

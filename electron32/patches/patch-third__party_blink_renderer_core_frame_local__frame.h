$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/local_frame.h.orig	2024-10-18 12:34:35.416178700 +0000
+++ third_party/blink/renderer/core/frame/local_frame.h
@@ -826,6 +826,7 @@ class CORE_EXPORT LocalFrame final
                             mojom::blink::EvaluationTiming,
                             mojom::blink::LoadEventBlockingOption,
                             WebScriptExecutionCallback,
+                            WebScriptExecutionCallbackUnmodified,
                             BackForwardCacheAware back_forward_cache_aware,
                             mojom::blink::WantResultOption,
                             mojom::blink::PromiseResultOption);

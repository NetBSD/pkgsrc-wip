$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/web/web_local_frame.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/public/web/web_local_frame.h
@@ -455,6 +455,7 @@ class BLINK_EXPORT WebLocalFrame : publi
                                     mojom::EvaluationTiming,
                                     mojom::LoadEventBlockingOption,
                                     WebScriptExecutionCallback,
+                                    WebScriptExecutionCallbackUnmodified,
                                     BackForwardCacheAware,
                                     mojom::WantResultOption,
                                     mojom::PromiseResultOption) = 0;

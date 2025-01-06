$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/web/web_local_frame.h.orig	2024-10-18 12:34:34.704506600 +0000
+++ third_party/blink/public/web/web_local_frame.h
@@ -446,6 +446,7 @@ class BLINK_EXPORT WebLocalFrame : publi
                                     mojom::EvaluationTiming,
                                     mojom::LoadEventBlockingOption,
                                     WebScriptExecutionCallback,
+                                    WebScriptExecutionCallbackUnmodified,
                                     BackForwardCacheAware,
                                     mojom::WantResultOption,
                                     mojom::PromiseResultOption) = 0;

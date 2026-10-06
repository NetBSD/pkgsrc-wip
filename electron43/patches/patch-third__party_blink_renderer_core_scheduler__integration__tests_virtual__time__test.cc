$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/scheduler_integration_tests/virtual_time_test.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/scheduler_integration_tests/virtual_time_test.cc
@@ -63,6 +63,7 @@ class VirtualTimeTest : public SimTest {
         mojom::blink::LoadEventBlockingOption::kDoNotBlock,
         WTF::BindOnce(&ScriptExecutionCallbackHelper::Completed,
                       base::Unretained(&callback_helper)),
+        base::NullCallback(),
         BackForwardCacheAware::kAllow,
         mojom::blink::WantResultOption::kWantResult,
         mojom::blink::PromiseResultOption::kDoNotWait);

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/electron_node/src/histogram.cc.orig	2025-04-18 18:41:29.000000000 +0000
+++ third_party/electron_node/src/histogram.cc
@@ -193,7 +193,8 @@ void HistogramBase::FastRecord(Local<Val
                                const int64_t value,
                                FastApiCallbackOptions& options) {
   if (value < 1) {
-    options.fallback = true;
+    Environment* env = Environment::GetCurrent(options.isolate);
+    THROW_ERR_OUT_OF_RANGE(env, "value is out of range");
     return;
   }
   HistogramBase* histogram;

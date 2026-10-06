$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/local_dom_window.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/core/frame/local_dom_window.cc
@@ -2235,6 +2235,8 @@ DOMWindow* LocalDOMWindow::open(v8::Isol
   WebWindowFeatures window_features =
       GetWindowFeaturesFromString(features, entered_window);
 
+  window_features.raw_features = features;
+
   if (window_features.is_partitioned_popin) {
     UseCounter::Count(*entered_window,
                       WebFeature::kPartitionedPopin_OpenAttempt);

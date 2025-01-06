$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/frame/local_dom_window.cc.orig	2024-10-18 12:34:35.416178700 +0000
+++ third_party/blink/renderer/core/frame/local_dom_window.cc
@@ -2240,6 +2240,8 @@ DOMWindow* LocalDOMWindow::open(v8::Isol
   WebWindowFeatures window_features =
       GetWindowFeaturesFromString(features, entered_window);
 
+  window_features.raw_features = features;
+
   // In fenced frames, we should always use `noopener`.
   if (GetFrame()->IsInFencedFrameTree()) {
     window_features.noopener = true;

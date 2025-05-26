$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/navigation_controller_impl_unittest.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/navigation_controller_impl_unittest.cc
@@ -163,6 +163,12 @@ class MockPageBroadcast : public blink::
               (network::mojom::AttributionSupport support),
               (override));
 
+  MOCK_METHOD(
+      void,
+      SetSchedulerThrottling,
+      (bool allowed),
+      (override));
+
   mojo::PendingAssociatedRemote<blink::mojom::PageBroadcast> GetRemote() {
     return receiver_.BindNewEndpointAndPassDedicatedRemote();
   }

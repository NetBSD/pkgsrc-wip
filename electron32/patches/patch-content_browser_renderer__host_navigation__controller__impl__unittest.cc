$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/navigation_controller_impl_unittest.cc.orig	2024-10-18 12:34:13.394909900 +0000
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

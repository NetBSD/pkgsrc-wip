$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/test/test_page_broadcast.h.orig	2024-10-18 12:34:16.201468700 +0000
+++ content/test/test_page_broadcast.h
@@ -50,6 +50,7 @@ class TestPageBroadcast : public blink::
       network::mojom::AttributionSupport support) override;
   void UpdateColorProviders(
       const blink::ColorProviderColorMaps& color_provider_colors) override;
+  void SetSchedulerThrottling(bool allowed) override {}
 
   mojo::AssociatedReceiver<blink::mojom::PageBroadcast> receiver_;
 };

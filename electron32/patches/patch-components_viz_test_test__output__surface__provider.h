$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/test/test_output_surface_provider.h.orig	2024-10-18 12:34:11.671806600 +0000
+++ components/viz/test/test_output_surface_provider.h
@@ -32,7 +32,8 @@ class TestOutputSurfaceProvider : public
       mojom::DisplayClient* display_client,
       DisplayCompositorMemoryAndTaskController* display_controller,
       const RendererSettings& renderer_settings,
-      const DebugRendererSettings* debug_settings) override;
+      const DebugRendererSettings* debug_settings,
+      bool offscreen) override;
   gpu::SharedImageManager* GetSharedImageManager() override;
   gpu::SyncPointManager* GetSyncPointManager() override;
 };

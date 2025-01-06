$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/display_embedder/output_surface_provider.h.orig	2024-10-18 12:34:11.619834000 +0000
+++ components/viz/service/display_embedder/output_surface_provider.h
@@ -38,7 +38,8 @@ class OutputSurfaceProvider {
       mojom::DisplayClient* display_client,
       DisplayCompositorMemoryAndTaskController* gpu_dependency,
       const RendererSettings& renderer_settings,
-      const DebugRendererSettings* debug_settings) = 0;
+      const DebugRendererSettings* debug_settings,
+      bool offscreen) = 0;
 
   virtual gpu::SharedImageManager* GetSharedImageManager() = 0;
   virtual gpu::SyncPointManager* GetSyncPointManager() = 0;

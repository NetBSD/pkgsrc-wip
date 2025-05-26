$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/display_embedder/output_surface_provider.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/viz/service/display_embedder/output_surface_provider.h
@@ -42,7 +42,8 @@ class OutputSurfaceProvider {
       mojom::DisplayClient* display_client,
       DisplayCompositorMemoryAndTaskController* gpu_dependency,
       const RendererSettings& renderer_settings,
-      const DebugRendererSettings* debug_settings) = 0;
+      const DebugRendererSettings* debug_settings,
+      bool offscreen) = 0;
 
   virtual gpu::SharedImageManager* GetSharedImageManager() = 0;
   virtual gpu::SyncPointManager* GetSyncPointManager() = 0;

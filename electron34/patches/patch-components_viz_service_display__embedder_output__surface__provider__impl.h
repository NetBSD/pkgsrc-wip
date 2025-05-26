$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/display_embedder/output_surface_provider_impl.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/viz/service/display_embedder/output_surface_provider_impl.h
@@ -54,7 +54,8 @@ class VIZ_SERVICE_EXPORT OutputSurfacePr
       mojom::DisplayClient* display_client,
       DisplayCompositorMemoryAndTaskController* gpu_dependency,
       const RendererSettings& renderer_settings,
-      const DebugRendererSettings* debug_settings) override;
+      const DebugRendererSettings* debug_settings,
+      bool offscreen) override;
 
   gpu::SharedImageManager* GetSharedImageManager() override;
   gpu::SyncPointManager* GetSyncPointManager() override;
@@ -63,7 +64,8 @@ class VIZ_SERVICE_EXPORT OutputSurfacePr
  private:
   std::unique_ptr<SoftwareOutputDevice> CreateSoftwareOutputDeviceForPlatform(
       gpu::SurfaceHandle surface_handle,
-      mojom::DisplayClient* display_client);
+      mojom::DisplayClient* display_client,
+      bool offscreen);
 
   const raw_ptr<GpuServiceImpl> gpu_service_impl_;
 

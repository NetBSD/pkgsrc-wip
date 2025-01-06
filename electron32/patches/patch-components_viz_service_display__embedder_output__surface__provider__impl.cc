$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/display_embedder/output_surface_provider_impl.cc.orig	2024-10-18 12:34:11.619834000 +0000
+++ components/viz/service/display_embedder/output_surface_provider_impl.cc
@@ -25,12 +25,14 @@
 #include "components/viz/service/display_embedder/server_shared_bitmap_manager.h"
 #include "components/viz/service/display_embedder/skia_output_surface_dependency_impl.h"
 #include "components/viz/service/display_embedder/skia_output_surface_impl.h"
+#include "components/viz/service/display_embedder/software_output_device_proxy.h"
 #include "components/viz/service/display_embedder/software_output_surface.h"
 #include "components/viz/service/gl/gpu_service_impl.h"
 #include "gpu/command_buffer/client/shared_memory_limits.h"
 #include "gpu/command_buffer/service/scheduler_sequence.h"
 #include "gpu/config/gpu_finch_features.h"
 #include "gpu/ipc/common/surface_handle.h"
+#include "services/viz/privileged/mojom/compositing/layered_window_updater.mojom.h"
 #include "ui/base/ui_base_switches.h"
 
 #if BUILDFLAG(IS_WIN)
@@ -94,7 +96,8 @@ std::unique_ptr<OutputSurface> OutputSur
     mojom::DisplayClient* display_client,
     DisplayCompositorMemoryAndTaskController* gpu_dependency,
     const RendererSettings& renderer_settings,
-    const DebugRendererSettings* debug_settings) {
+    const DebugRendererSettings* debug_settings,
+    bool offscreen) {
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   if (surface_handle == gpu::kNullSurfaceHandle)
     return std::make_unique<OutputSurfaceUnified>();
@@ -102,7 +105,7 @@ std::unique_ptr<OutputSurface> OutputSur
 
   if (!gpu_compositing) {
     return std::make_unique<SoftwareOutputSurface>(
-        CreateSoftwareOutputDeviceForPlatform(surface_handle, display_client));
+        CreateSoftwareOutputDeviceForPlatform(surface_handle, display_client, offscreen));
   } else {
     DCHECK(gpu_dependency);
 
@@ -142,10 +145,22 @@ std::unique_ptr<OutputSurface> OutputSur
 std::unique_ptr<SoftwareOutputDevice>
 OutputSurfaceProviderImpl::CreateSoftwareOutputDeviceForPlatform(
     gpu::SurfaceHandle surface_handle,
-    mojom::DisplayClient* display_client) {
+    mojom::DisplayClient* display_client,
+    bool offscreen) {
   if (headless_)
     return std::make_unique<SoftwareOutputDevice>();
 
+#if !BUILDFLAG(IS_APPLE)
+  if (offscreen) {
+    DCHECK(display_client);
+    mojo::PendingRemote<mojom::LayeredWindowUpdater> layered_window_updater;
+    display_client->CreateLayeredWindowUpdater(
+        layered_window_updater.InitWithNewPipeAndPassReceiver());
+    return std::make_unique<SoftwareOutputDeviceProxy>(
+        std::move(layered_window_updater));
+  }
+#endif
+
 #if BUILDFLAG(IS_WIN)
   return CreateSoftwareOutputDeviceWin(surface_handle, &output_device_backing_,
                                        display_client);

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/test/test_output_surface_provider.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/viz/test/test_output_surface_provider.cc
@@ -30,7 +30,8 @@ std::unique_ptr<OutputSurface> TestOutpu
     mojom::DisplayClient* display_client,
     DisplayCompositorMemoryAndTaskController* display_controller,
     const RendererSettings& renderer_settings,
-    const DebugRendererSettings* debug_settings) {
+    const DebugRendererSettings* debug_settings,
+    bool offscreen) {
   if (gpu_compositing) {
     return FakeSkiaOutputSurface::Create3d();
   } else {

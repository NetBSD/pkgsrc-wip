$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/accelerated_widget_mac/ca_layer_tree_coordinator.mm.orig	2025-02-24 19:59:26.000000000 +0000
+++ ui/accelerated_widget_mac/ca_layer_tree_coordinator.mm
@@ -10,6 +10,7 @@
 #include "base/mac/mac_util.h"
 #include "base/task/single_thread_task_runner.h"
 #include "base/trace_event/trace_event.h"
+#include "electron/mas.h"
 #include "ui/base/cocoa/animation_utils.h"
 #include "ui/base/cocoa/remote_layer_api.h"
 #include "ui/gfx/ca_layer_params.h"
@@ -33,6 +34,7 @@ CALayerTreeCoordinator::CALayerTreeCoord
       new_presentation_feedback_timestamps_(
           new_presentation_feedback_timestamps),
       buffer_presented_callback_(buffer_presented_callback) {
+#if !IS_MAS_BUILD()
   if (allow_remote_layers_) {
     root_ca_layer_ = [[CALayer alloc] init];
 #if BUILDFLAG(IS_MAC)
@@ -61,6 +63,7 @@ CALayerTreeCoordinator::CALayerTreeCoord
 #endif
     ca_context_.layer = root_ca_layer_;
   }
+#endif
 }
 
 CALayerTreeCoordinator::~CALayerTreeCoordinator() = default;
@@ -164,9 +167,13 @@ void CALayerTreeCoordinator::CommitPrese
     TRACE_EVENT_INSTANT2("test_gpu", "SwapBuffers", TRACE_EVENT_SCOPE_THREAD,
                          "GLImpl", static_cast<int>(gl::GetGLImplementation()),
                          "width", pixel_size_.width());
+#if !IS_MAS_BUILD()
     if (allow_remote_layers_) {
       params.ca_context_id = [ca_context_ contextId];
     } else {
+#else
+    if (true) {
+#endif
       IOSurfaceRef io_surface = frame->layer_tree->GetContentIOSurface();
       if (io_surface) {
         DCHECK(!allow_remote_layers_);

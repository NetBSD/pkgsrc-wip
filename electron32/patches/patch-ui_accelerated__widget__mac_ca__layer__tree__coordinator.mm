$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/accelerated_widget_mac/ca_layer_tree_coordinator.mm.orig	2024-10-18 12:35:11.560735000 +0000
+++ ui/accelerated_widget_mac/ca_layer_tree_coordinator.mm
@@ -33,6 +33,7 @@ CALayerTreeCoordinator::CALayerTreeCoord
       new_presentation_feedback_timestamps_(
           new_presentation_feedback_timestamps),
       buffer_presented_callback_(buffer_presented_callback) {
+#if !IS_MAS_BUILD()
   if (allow_remote_layers_) {
     root_ca_layer_ = [[CALayer alloc] init];
 #if BUILDFLAG(IS_MAC)
@@ -61,6 +62,7 @@ CALayerTreeCoordinator::CALayerTreeCoord
 #endif
     ca_context_.layer = root_ca_layer_;
   }
+#endif
 }
 
 CALayerTreeCoordinator::~CALayerTreeCoordinator() = default;
@@ -164,9 +166,13 @@ void CALayerTreeCoordinator::CommitPrese
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

$NetBSD$

--- components/viz/service/display_embedder/software_output_surface.h.orig	2020-07-08 21:40:41.000000000 +0000
+++ components/viz/service/display_embedder/software_output_surface.h
@@ -49,7 +49,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputS
       UpdateVSyncParametersCallback callback) override;
   void SetDisplayTransformHint(gfx::OverlayTransform transform) override {}
   gfx::OverlayTransform GetDisplayTransform() override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif
@@ -72,7 +72,7 @@ class VIZ_SERVICE_EXPORT SoftwareOutputS
   std::queue<std::vector<ui::LatencyInfo>> stored_latency_info_;
   ui::LatencyTracker latency_tracker_;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   bool needs_swap_size_notifications_ = false;
 #endif
 

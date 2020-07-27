$NetBSD$

--- components/viz/test/fake_output_surface.h.orig	2020-07-08 21:40:42.000000000 +0000
+++ components/viz/test/fake_output_surface.h
@@ -82,7 +82,7 @@ class FakeOutputSurface : public OutputS
       UpdateVSyncParametersCallback callback) override;
   void SetDisplayTransformHint(gfx::OverlayTransform transform) override;
   gfx::OverlayTransform GetDisplayTransform() override;
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   void SetNeedsSwapSizeNotifications(
       bool needs_swap_size_notifications) override;
 #endif

$NetBSD$

--- components/viz/test/fake_output_surface.cc.orig	2020-07-08 21:40:42.000000000 +0000
+++ components/viz/test/fake_output_surface.cc
@@ -111,7 +111,7 @@ gfx::OverlayTransform FakeOutputSurface:
                                          : gfx::OVERLAY_TRANSFORM_NONE;
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 void FakeOutputSurface::SetNeedsSwapSizeNotifications(
     bool needs_swap_size_notifications) {}
 #endif

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/host/layered_window_updater_impl.h.orig	2024-10-18 12:34:11.531880000 +0000
+++ components/viz/host/layered_window_updater_impl.h
@@ -38,7 +38,7 @@ class VIZ_HOST_EXPORT LayeredWindowUpdat
   // mojom::LayeredWindowUpdater implementation.
   void OnAllocatedSharedMemory(const gfx::Size& pixel_size,
                                base::UnsafeSharedMemoryRegion region) override;
-  void Draw(DrawCallback draw_callback) override;
+  void Draw(const gfx::Rect& damage_rect, DrawCallback draw_callback) override;
 
  private:
   const HWND hwnd_;

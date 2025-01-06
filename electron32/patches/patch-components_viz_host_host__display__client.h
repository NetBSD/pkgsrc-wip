$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/host/host_display_client.h.orig	2024-10-18 12:34:11.531880000 +0000
+++ components/viz/host/host_display_client.h
@@ -39,6 +39,9 @@ class VIZ_HOST_EXPORT HostDisplayClient 
   gfx::AcceleratedWidget widget() const { return widget_; }
 #endif
 
+  void CreateLayeredWindowUpdater(
+      mojo::PendingReceiver<mojom::LayeredWindowUpdater> receiver) override;
+
  private:
   // mojom::DisplayClient implementation:
 #if BUILDFLAG(IS_APPLE)
@@ -47,12 +50,10 @@ class VIZ_HOST_EXPORT HostDisplayClient 
 #endif
 
 #if BUILDFLAG(IS_WIN)
-  void CreateLayeredWindowUpdater(
-      mojo::PendingReceiver<mojom::LayeredWindowUpdater> receiver) override;
   void AddChildWindowToBrowser(gpu::SurfaceHandle child_window) override;
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override;
 #endif  // BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
 

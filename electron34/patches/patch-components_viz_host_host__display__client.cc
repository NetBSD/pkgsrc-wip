$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/host/host_display_client.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ components/viz/host/host_display_client.cc
@@ -48,9 +48,9 @@ void HostDisplayClient::OnDisplayReceive
 }
 #endif
 
-#if BUILDFLAG(IS_WIN)
 void HostDisplayClient::CreateLayeredWindowUpdater(
     mojo::PendingReceiver<mojom::LayeredWindowUpdater> receiver) {
+#if BUILDFLAG(IS_WIN)
   if (!NeedsToUseLayerWindow(widget_)) {
     DLOG(ERROR) << "HWND shouldn't be using a layered window";
     return;
@@ -58,14 +58,22 @@ void HostDisplayClient::CreateLayeredWin
 
   layered_window_updater_ =
       std::make_unique<LayeredWindowUpdaterImpl>(widget_, std::move(receiver));
+
+#else
+  CHECK(false) << "Chromium is calling CreateLayeredWindowUpdater for non-OSR "
+                  "windows on POSIX platforms, something is wrong with "
+                  "Electron's OSR implementation.";
+#endif
 }
+
+#if BUILDFLAG(IS_WIN)
 void HostDisplayClient::AddChildWindowToBrowser(
     gpu::SurfaceHandle child_window) {
   NOTREACHED_IN_MIGRATION();
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void HostDisplayClient::DidCompleteSwapWithNewSize(const gfx::Size& size) {
   NOTIMPLEMENTED();
 }

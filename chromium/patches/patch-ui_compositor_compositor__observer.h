$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/compositor/compositor_observer.h.orig	2024-07-24 02:45:10.416053300 +0000
+++ ui/compositor/compositor_observer.h
@@ -52,7 +52,7 @@ class COMPOSITOR_EXPORT CompositorObserv
   // Called when a child of the compositor is resizing.
   virtual void OnCompositingChildResizing(Compositor* compositor) {}
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   // Called when a swap with new size is completed.
   virtual void OnCompositingCompleteSwapWithNewSize(ui::Compositor* compositor,
                                                     const gfx::Size& size) {}

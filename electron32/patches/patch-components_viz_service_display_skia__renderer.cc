$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/viz/service/display/skia_renderer.cc.orig	2024-10-18 12:34:11.599844200 +0000
+++ components/viz/service/display/skia_renderer.cc
@@ -1441,7 +1441,7 @@ void SkiaRenderer::ClearFramebuffer() {
   if (current_frame()->current_render_pass->has_transparent_background) {
     ClearCanvas(SkColors::kTransparent);
   } else {
-#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX)
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // On DEBUG builds, opaque render passes are cleared to blue
     // to easily see regions that were not drawn on the screen.
     // ClearCavas() call causes slight pixel difference, so linux-ref and

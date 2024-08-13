$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.cc.orig	2024-08-06 19:52:29.254304000 +0000
+++ media/mojo/mojom/stable/stable_video_decoder_types_mojom_traits.cc
@@ -837,7 +837,7 @@ const gfx::GpuMemoryBufferId& StructTrai
   return input.id;
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // static
 gfx::NativePixmapHandle StructTraits<
     media::stable::mojom::NativeGpuMemoryBufferHandleDataView,
@@ -858,7 +858,7 @@ bool StructTraits<media::stable::mojom::
 
   output->type = gfx::NATIVE_PIXMAP;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (!data.ReadPlatformHandle(&output->native_pixmap_handle))
     return false;
   return true;

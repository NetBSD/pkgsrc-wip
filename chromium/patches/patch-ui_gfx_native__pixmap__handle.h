$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/native_pixmap_handle.h.orig	2025-07-21 19:32:31.000000000 +0000
+++ ui/gfx/native_pixmap_handle.h
@@ -14,7 +14,7 @@
 #include "build/build_config.h"
 #include "ui/gfx/buffer_types.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/files/scoped_file.h"
 #endif
 
@@ -34,7 +34,7 @@ struct COMPONENT_EXPORT(GFX) NativePixma
   NativePixmapPlane(int stride,
                     int offset,
                     uint64_t size
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
                     ,
                     base::ScopedFD fd
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -55,7 +55,7 @@ struct COMPONENT_EXPORT(GFX) NativePixma
   // This is necessary to map the buffers.
   uint64_t size;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // File descriptor for the underlying memory object (usually dmabuf).
   base::ScopedFD fd;
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -78,7 +78,7 @@ struct COMPONENT_EXPORT(GFX) NativePixma
 
   std::vector<NativePixmapPlane> planes;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The modifier is retrieved from GBM library and passed to EGL driver.
   // Generally it's platform specific, and we don't need to modify it in
   // Chromium code. Also one per plane per entry.

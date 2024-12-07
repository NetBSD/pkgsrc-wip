$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/test/video_frame_helpers.cc.orig	2024-12-03 23:30:23.209055700 +0000
+++ media/gpu/test/video_frame_helpers.cc
@@ -22,7 +22,7 @@
 #include "ui/gfx/buffer_format_util.h"
 #include "ui/gfx/gpu_memory_buffer.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 

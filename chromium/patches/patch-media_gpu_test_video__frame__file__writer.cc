$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/gpu/test/video_frame_file_writer.cc.orig	2024-10-26 07:00:21.655713600 +0000
+++ media/gpu/test/video_frame_file_writer.cc
@@ -26,7 +26,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 #include "ui/gfx/codec/png_codec.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 

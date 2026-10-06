$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/gpu/test/video_frame_file_writer.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/gpu/test/video_frame_file_writer.cc
@@ -26,7 +26,7 @@
 #include "testing/gtest/include/gtest/gtest.h"
 #include "ui/gfx/codec/png_codec.h"
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <sys/mman.h>
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
 

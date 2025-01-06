$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- gpu/command_buffer/tests/gl_gpu_memory_buffer_unittest.cc.orig	2024-10-18 12:34:18.824143200 +0000
+++ gpu/command_buffer/tests/gl_gpu_memory_buffer_unittest.cc
@@ -27,7 +27,7 @@
 #include "ui/gfx/half_float.h"
 #include "ui/gl/test/gl_test_support.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "gpu/ipc/common/gpu_memory_buffer_impl_native_pixmap.h"
 #include "ui/gfx/linux/client_native_pixmap_factory_dmabuf.h"
 #endif
@@ -70,7 +70,7 @@ class GpuMemoryBufferTest : public testi
   GLManager gl_;
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 class GpuMemoryBufferTestEGL : public testing::Test,
                                public gpu::GpuCommandBufferTestEGL {
  public:

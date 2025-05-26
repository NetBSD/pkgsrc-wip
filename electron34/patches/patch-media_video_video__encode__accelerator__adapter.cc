$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- media/video/video_encode_accelerator_adapter.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ media/video/video_encode_accelerator_adapter.cc
@@ -159,7 +159,7 @@ VideoEncodeAccelerator::Config SetUpVeaC
     config.input_format = PIXEL_FORMAT_I420;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (format != PIXEL_FORMAT_I420 ||
       !VideoFrame::IsStorageTypeMappable(storage_type)) {
     // ChromeOS/Linux hardware video encoders supports I420 on-memory
@@ -518,7 +518,7 @@ void VideoEncodeAcceleratorAdapter::Init
       profile_, options_, format, first_frame->storage_type(),
       supported_rc_modes_, required_encoder_type_, is_gpu_supported_format);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Linux/ChromeOS require a special configuration to use dmabuf storage.
   // We need to keep sending frames the same way the first frame was sent.
   // Other platforms will happily mix GpuMemoryBuffer storage with regular

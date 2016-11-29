$NetBSD$

--- content/renderer/render_thread_impl.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/renderer/render_thread_impl.cc
@@ -1455,7 +1455,7 @@ media::GpuVideoAcceleratorFactories* Ren
   const bool enable_video_accelerator =
       !cmd_line->HasSwitch(switches::kDisableAcceleratedVideoDecode);
   const bool enable_gpu_memory_buffer_video_frames =
-#if defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
       !cmd_line->HasSwitch(switches::kDisableGpuMemoryBufferVideoFrames) &&
       !cmd_line->HasSwitch(switches::kDisableGpuCompositing) &&
       !gpu_channel_host->gpu_info().software_rendering;

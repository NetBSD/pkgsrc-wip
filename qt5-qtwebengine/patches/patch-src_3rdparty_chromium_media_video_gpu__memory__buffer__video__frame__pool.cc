$NetBSD$

--- src/3rdparty/chromium/media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2020-07-08 21:40:46.000000000 +0000
+++ src/3rdparty/chromium/media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -573,7 +573,7 @@ void GpuMemoryBufferVideoFramePool::Pool
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 

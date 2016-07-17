$NetBSD$

--- gpu/config/gpu_info_collector.cc.orig	2016-06-24 01:02:22.000000000 +0000
+++ gpu/config/gpu_info_collector.cc
@@ -167,8 +167,10 @@ CollectInfoResult CollectGraphicsInfoGL(
   gpu_info->pixel_shader_version = glsl_version;
   gpu_info->vertex_shader_version = glsl_version;
 
+#ifndef __FreeBSD__
   IdentifyActiveGPU(gpu_info);
   return CollectDriverInfoGL(gpu_info);
+#endif
 }
 
 void MergeGPUInfoGL(GPUInfo* basic_gpu_info,

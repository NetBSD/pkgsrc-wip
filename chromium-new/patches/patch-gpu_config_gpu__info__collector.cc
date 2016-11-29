$NetBSD$

--- gpu/config/gpu_info_collector.cc.orig	2016-11-10 20:02:15.000000000 +0000
+++ gpu/config/gpu_info_collector.cc
@@ -181,8 +181,10 @@ CollectInfoResult CollectGraphicsInfoGL(
   gpu_info->pixel_shader_version = glsl_version;
   gpu_info->vertex_shader_version = glsl_version;
 
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
   IdentifyActiveGPU(gpu_info);
   return CollectDriverInfoGL(gpu_info);
+#endif
 }
 
 void MergeGPUInfoGL(GPUInfo* basic_gpu_info,

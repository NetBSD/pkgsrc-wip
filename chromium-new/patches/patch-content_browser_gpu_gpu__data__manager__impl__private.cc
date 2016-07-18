$NetBSD$

--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2016-06-24 01:02:20.000000000 +0000
+++ content/browser/gpu/gpu_data_manager_impl_private.cc
@@ -470,8 +470,10 @@ void GpuDataManagerImplPrivate::SetGLStr
   gpu_info.gl_renderer = gl_renderer;
   gpu_info.gl_version = gl_version;
 
+#if !defined(OS_FREEBSD) && !defined(OS_NETBSD)
   gpu::IdentifyActiveGPU(&gpu_info);
   gpu::CollectDriverInfoGL(&gpu_info);
+#endif
 
   UpdateGpuInfo(gpu_info);
   UpdateGpuSwitchingManager(gpu_info);
@@ -515,10 +517,12 @@ void GpuDataManagerImplPrivate::Initiali
     // Also declare the driver_vendor to be osmesa to be able to specify
     // exceptions based on driver_vendor==osmesa for some blacklist rules.
     gpu_info.driver_vendor = gfx::kGLImplementationOSMesaName;
+#if !defined(OS_FREEBSD) && !defined(OS_NETBSD)
   } else {
     TRACE_EVENT0("startup",
       "GpuDataManagerImpl::Initialize:CollectBasicGraphicsInfo");
     gpu::CollectBasicGraphicsInfo(&gpu_info);
+#endif
 
     if (command_line->HasSwitch(switches::kGpuTestingVendorId) &&
         command_line->HasSwitch(switches::kGpuTestingDeviceId)) {
@@ -617,7 +621,9 @@ void GpuDataManagerImplPrivate::UpdateGp
     return;
 
   bool was_info_available = IsCompleteGpuInfoAvailable();
+#if !defined(OS_FREEBSD) && !defined(OS_NETBSD)
   gpu::MergeGPUInfo(&gpu_info_, gpu_info);
+#endif
   if (IsCompleteGpuInfoAvailable()) {
     complete_gpu_info_already_requested_ = true;
   } else if (was_info_available) {

$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/ipc/service/gpu_init.cc.orig	2025-03-31 15:23:48.000000000 +0000
+++ gpu/ipc/service/gpu_init.cc
@@ -153,7 +153,7 @@ void InitializePlatformOverlaySettings(G
 
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CASTOS)
 bool CanAccessDeviceFile(const GPUInfo& gpu_info) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (gpu_info.gpu.vendor_id != 0x10de ||  // NVIDIA
       gpu_info.gpu.driver_vendor != "NVIDIA")
     return true;
@@ -393,7 +393,7 @@ bool GpuInit::InitializeAndStartSandbox(
   enable_watchdog = false;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool gpu_sandbox_start_early = gpu_preferences_.gpu_sandbox_start_early;
 #else   // !(BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
   // For some reasons MacOSX's VideoToolbox might crash when called after
@@ -431,7 +431,7 @@ bool GpuInit::InitializeAndStartSandbox(
   }
 
   bool attempted_startsandbox = false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // On Chrome OS ARM Mali, GPU driver userspace creates threads when
   // initializing a GL context, so start the sandbox early.
   // TODO(zmo): Need to collect OS version before this.
@@ -528,7 +528,7 @@ bool GpuInit::InitializeAndStartSandbox(
     gpu_preferences_.gr_context_type = GrContextType::kGL;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // The ContentSandboxHelper is currently the only one implementation of
   // GpuSandboxHelper and it has no dependency. Except on Linux where
   // VaapiWrapper checks the GL implementation to determine which display
@@ -590,7 +590,7 @@ bool GpuInit::InitializeAndStartSandbox(
           command_line, gpu_feature_info_,
           gpu_preferences_.disable_software_rasterizer, false);
       if (gl_use_swiftshader_) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         VLOG(1) << "Quit GPU process launch to fallback to SwiftShader cleanly "
                 << "on Linux";
         return false;
@@ -758,7 +758,7 @@ bool GpuInit::InitializeAndStartSandbox(
               ->GetSupportedFormatsForGLNativePixmapImport();
 #endif  // BUILDFLAG(IS_OZONE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.
@@ -810,7 +810,7 @@ bool GpuInit::InitializeAndStartSandbox(
       }
     }
   }
-#if BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_CHROMEOS_DEVICE))
   if (!gl_disabled && !gl_use_swiftshader_ && std::getenv("RUNNING_UNDER_RR")) {
     // https://rr-project.org/ is a Linux-only record-and-replay debugger that
@@ -1014,7 +1014,7 @@ void GpuInit::InitializeInProcess(base::
   }
   bool gl_disabled = gl::GetGLImplementation() == gl::kGLImplementationDisabled;
 
-#if BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_CHROMEOS_DEVICE))
   if (!gl_disabled && !gl_use_swiftshader_ && std::getenv("RUNNING_UNDER_RR")) {
     // https://rr-project.org/ is a Linux-only record-and-replay debugger that
@@ -1069,7 +1069,7 @@ void GpuInit::InitializeInProcess(base::
     }
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Driver may create a compatibility profile context when collect graphics
   // information on Linux platform. Try to collect graphics information
   // based on core profile context after disabling platform extensions.

$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/gpu/gpu_child_thread.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ content/gpu/gpu_child_thread.cc
@@ -57,7 +57,7 @@
 #include "third_party/skia/include/ports/SkFontConfigInterface.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
 
@@ -147,7 +147,8 @@ void GpuChildThread::Init(const base::Ti
 
   viz_main_.gpu_service()->set_start_time(process_start_time);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// XXX BSD
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   SandboxedProcessThreadTypeHandler::NotifyMainChildThreadCreated();
 #endif
 

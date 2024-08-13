$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/utility/services.cc.orig	2024-08-06 19:52:26.374060600 +0000
+++ content/utility/services.cc
@@ -74,7 +74,7 @@
 extern sandbox::TargetServices* g_utility_target_services;
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/mojo/services/mojo_video_encode_accelerator_provider_factory.h"
 #include "sandbox/linux/services/libc_interceptor.h"
 #include "sandbox/policy/mojom/sandbox.mojom.h"
@@ -97,7 +97,7 @@ extern sandbox::TargetServices* g_utilit
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) && (BUILDFLAG(USE_VAAPI) ||
         // BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 #include "content/common/features.h"
 #include "media/mojo/services/stable_video_decoder_factory_process_service.h"  // nogncheck
@@ -115,13 +115,13 @@ extern sandbox::TargetServices* g_utilit
 #endif  // BUILDFLAG(ENABLE_ACCESSIBILITY_SERVICE)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || \
-    BUILDFLAG(ENABLE_VIDEO_EFFECTS)
+    BUILDFLAG(ENABLE_VIDEO_EFFECTS) || BUILDFLAG(IS_BSD)
 #include "services/viz/public/cpp/gpu/gpu.h"
 #include "services/viz/public/mojom/gpu.mojom.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(ENABLE_VIDEO_EFFECTS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "media/capture/capture_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS_ASH)
@@ -239,7 +239,7 @@ auto RunAudio(mojo::PendingReceiver<audi
       << "task_policy_set TASK_QOS_POLICY";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   auto* command_line = base::CommandLine::ForCurrentProcess();
   if (sandbox::policy::SandboxTypeFromCommandLine(*command_line) ==
       sandbox::mojom::Sandbox::kNoSandbox) {
@@ -328,7 +328,7 @@ auto RunVideoCapture(
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
   auto service = std::make_unique<UtilityThreadVideoCaptureServiceImpl>(
       std::move(receiver), base::SingleThreadTaskRunner::GetCurrentDefault());
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   {
 #else
@@ -384,7 +384,7 @@ auto RunOOPArcVideoAcceleratorFactorySer
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) && (BUILDFLAG(USE_VAAPI) ||
         // BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 auto RunStableVideoDecoderFactoryProcessService(
     mojo::PendingReceiver<
@@ -395,7 +395,7 @@ auto RunStableVideoDecoderFactoryProcess
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) &&
         // (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 auto RunVideoEncodeAcceleratorProviderFactory(
     mojo::PendingReceiver<media::mojom::VideoEncodeAcceleratorProviderFactory>
         receiver) {
@@ -418,7 +418,7 @@ void RegisterIOThreadServices(mojo::Serv
   // loop of type IO that can get notified when pipes have data.
   services.Add(RunNetworkService);
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
   if (base::FeatureList::IsEnabled(
           features::kRunStableVideoDecoderFactoryProcessServiceOnIOThread)) {
@@ -470,7 +470,7 @@ void RegisterMainThreadServices(mojo::Se
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH) && (BUILDFLAG(USE_VAAPI) ||
         // BUILDFLAG(USE_V4L2_CODEC))
 
-#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) && \
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)) && \
     (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
   if (!base::FeatureList::IsEnabled(
           features::kRunStableVideoDecoderFactoryProcessServiceOnIOThread)) {
@@ -479,7 +479,7 @@ void RegisterMainThreadServices(mojo::Se
 #endif  // (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)) &&
         // (BUILDFLAG(USE_VAAPI) || BUILDFLAG(USE_V4L2_CODEC))
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   services.Add(RunVideoEncodeAcceleratorProviderFactory);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 

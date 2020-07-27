$NetBSD$

--- media/capture/video/fake_video_capture_device_factory.cc.orig	2020-07-08 21:41:48.000000000 +0000
+++ media/capture/video/fake_video_capture_device_factory.cc
@@ -208,7 +208,7 @@ void FakeVideoCaptureDeviceFactory::GetD
   for (const auto& entry : devices_config_) {
     device_descriptors->emplace_back(
         base::StringPrintf("fake_device_%d", entry_index), entry.device_id,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE,
 #elif defined(OS_MACOSX)
         VideoCaptureApi::MACOSX_AVFOUNDATION,

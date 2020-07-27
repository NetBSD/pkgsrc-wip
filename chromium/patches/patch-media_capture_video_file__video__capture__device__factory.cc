$NetBSD$

--- media/capture/video/file_video_capture_device_factory.cc.orig	2020-07-08 21:40:45.000000000 +0000
+++ media/capture/video/file_video_capture_device_factory.cc
@@ -54,7 +54,7 @@ void FileVideoCaptureDeviceFactory::GetD
 #elif defined(OS_MACOSX)
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureApi::MACOSX_AVFOUNDATION
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE
 #else

$NetBSD$

--- media/capture/video/file_video_capture_device_factory.cc.orig	2016-11-10 20:02:15.000000000 +0000
+++ media/capture/video/file_video_capture_device_factory.cc
@@ -49,7 +49,7 @@ void FileVideoCaptureDeviceFactory::GetD
 #elif defined(OS_MACOSX)
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureApi::MACOSX_AVFOUNDATION
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
       command_line_file_path.value(), kFileVideoCaptureDeviceName,
       VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE
 #else

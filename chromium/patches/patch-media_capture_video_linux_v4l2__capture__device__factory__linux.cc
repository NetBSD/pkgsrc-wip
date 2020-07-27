$NetBSD$

--- media/capture/video/linux/video_capture_device_factory_linux.cc.orig	2020-07-15 18:56:47.000000000 +0000
+++ media/capture/video/linux/video_capture_device_factory_linux.cc
@@ -21,7 +21,7 @@
 #include "media/capture/video/linux/scoped_v4l2_device_fd.h"
 #include "media/capture/video/linux/video_capture_device_linux.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -256,6 +256,7 @@ int VideoCaptureDeviceFactoryLinux::DoIo
 // Check if the video capture device supports at least one of pan, tilt and zoom
 // controls.
 bool VideoCaptureDeviceFactoryLinux::IsPanTiltZoomSupported(int fd) {
+#if !defined(OS_NETBSD)
   for (int control_id : {V4L2_CID_PAN_ABSOLUTE, V4L2_CID_TILT_ABSOLUTE,
                          V4L2_CID_ZOOM_ABSOLUTE}) {
     v4l2_queryctrl range = {};
@@ -266,6 +267,7 @@ bool VideoCaptureDeviceFactoryLinux::IsP
       return true;
     }
   }
+#endif
   return false;
 }
 
@@ -292,6 +294,7 @@ std::vector<float> VideoCaptureDeviceFac
     uint32_t fourcc,
     uint32_t width,
     uint32_t height) {
+#if !defined(OS_NETBSD)
   std::vector<float> frame_rates;
 
   v4l2_frmivalenum frame_interval = {};
@@ -318,6 +321,9 @@ std::vector<float> VideoCaptureDeviceFac
   if (frame_rates.empty())
     frame_rates.push_back(0);
   return frame_rates;
+#else
+  NOTIMPLEMENTED_LOG_ONCE();
+#endif
 }
 
 void VideoCaptureDeviceFactoryLinux::GetSupportedFormatsForV4L2BufferType(

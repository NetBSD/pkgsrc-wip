$NetBSD$

--- media/capture/video/linux/video_capture_device_factory_linux.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/capture/video/linux/video_capture_device_factory_linux.cc
@@ -14,7 +14,7 @@
 #include "base/posix/eintr_wrapper.h"
 #include "build/build_config.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -53,6 +53,7 @@ static std::list<float> GetFrameRateList
                                          uint32_t height) {
   std::list<float> frame_rates;
 
+#if !defined(__NetBSD__)
   v4l2_frmivalenum frame_interval = {};
   frame_interval.pixel_format = fourcc;
   frame_interval.width = width;
@@ -73,6 +74,7 @@ static std::list<float> GetFrameRateList
       break;
     }
   }
+#endif
   // Some devices, e.g. Kinect, do not enumerate any frame rates, see
   // http://crbug.com/412284. Set their frame_rate to zero.
   if (frame_rates.empty())
@@ -83,6 +85,7 @@ static std::list<float> GetFrameRateList
 static void GetSupportedFormatsForV4L2BufferType(
     int fd,
     media::VideoCaptureFormats* supported_formats) {
+#if !defined(__NetBSD__)
   v4l2_fmtdesc v4l2_format = {};
   v4l2_format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
   for (; HANDLE_EINTR(ioctl(fd, VIDIOC_ENUM_FMT, &v4l2_format)) == 0;
@@ -118,6 +121,9 @@ static void GetSupportedFormatsForV4L2Bu
       }
     }
   }
+#else
+  NOTIMPLEMENTED();
+#endif
 }
 
 VideoCaptureDeviceFactoryLinux::VideoCaptureDeviceFactoryLinux(

$NetBSD$

--- media/capture/video/linux/video_capture_device_linux.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/capture/video/linux/video_capture_device_linux.cc
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -44,6 +44,7 @@ static bool ReadIdFile(const std::string
   return true;
 }
 
+#if !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 // Translates Video4Linux pixel formats to Chromium pixel formats.
 // static
 VideoPixelFormat VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
@@ -57,6 +58,7 @@ std::list<uint32_t> VideoCaptureDeviceLi
     bool favour_mjpeg) {
   return V4L2CaptureDelegate::GetListOfUsableFourCcs(favour_mjpeg);
 }
+#endif // !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 
 const std::string VideoCaptureDevice::Name::GetModel() const {
   // |unique_id| is of the form "/dev/video2".  |file_name| is "video2".
@@ -90,6 +92,7 @@ VideoCaptureDeviceLinux::~VideoCaptureDe
   v4l2_thread_.Stop();
 }
 
+#if !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     scoped_ptr<VideoCaptureDevice::Client> client) {
@@ -113,7 +116,13 @@ void VideoCaptureDeviceLinux::AllocateAn
                  params.requested_format.frame_size.height(),
                  params.requested_format.frame_rate, base::Passed(&client)));
 }
+#else // !defined(OS_FREEBSD) && !defined(OS_NETBSD)
+void VideoCaptureDeviceLinux::AllocateAndStart(
+    const VideoCaptureParams& params,
+    scoped_ptr<VideoCaptureDevice::Client> client) {}
+#endif // !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 
+#if !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 void VideoCaptureDeviceLinux::StopAndDeAllocate() {
   if (!v4l2_thread_.IsRunning())
     return;  // Wrong state.
@@ -124,7 +133,11 @@ void VideoCaptureDeviceLinux::StopAndDeA
 
   capture_impl_ = NULL;
 }
+#else // !defined(OS_FREEBSD) && !defined(OS_NETBSD)
+void VideoCaptureDeviceLinux::StopAndDeAllocate() {}
+#endif // !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 
+#if !defined(OS_FREEBSD) && !defined(OS_NETBSD)
 void VideoCaptureDeviceLinux::SetRotation(int rotation) {
   if (v4l2_thread_.IsRunning()) {
     v4l2_thread_.message_loop()->PostTask(
@@ -132,10 +145,14 @@ void VideoCaptureDeviceLinux::SetRotatio
         base::Bind(&V4L2CaptureDelegate::SetRotation, capture_impl_, rotation));
   }
 }
+#else // !defined(OS_FREEBSD) && !defined(OS_NETBSD)
+void VideoCaptureDeviceLinux::SetRotation(int rotation) {}
+#endif // !defined(OS_FREEBSD)
 
 // static
 int VideoCaptureDeviceLinux::TranslatePowerLineFrequencyToV4L2(
     PowerLineFrequency frequency) {
+#if !defined(OS_NETBSD)
   switch (frequency) {
     case media::PowerLineFrequency::FREQUENCY_50HZ:
       return V4L2_CID_POWER_LINE_FREQUENCY_50HZ;
@@ -145,6 +162,9 @@ int VideoCaptureDeviceLinux::TranslatePo
       // If we have no idea of the frequency, at least try and set it to AUTO.
       return V4L2_CID_POWER_LINE_FREQUENCY_AUTO;
   }
+#else
+  return 0;  
+#endif
 }
 
 }  // namespace media

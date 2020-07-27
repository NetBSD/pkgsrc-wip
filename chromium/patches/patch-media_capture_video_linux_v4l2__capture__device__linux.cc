$NetBSD$

--- media/capture/video/linux/video_capture_device_linux.cc.orig	2020-07-15 18:55:59.000000000 +0000
+++ media/capture/video/linux/video_capture_device_linux.cc
@@ -13,7 +13,7 @@
 #include "build/build_config.h"
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
-#if defined(OS_OPENBSD)
+#if defined(OS_OPENBSD) || defined(OS_NETBSD)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
@@ -23,6 +23,7 @@ namespace media {
 
 namespace {
 
+#if !defined(OS_NETBSD)
 int TranslatePowerLineFrequencyToV4L2(PowerLineFrequency frequency) {
   switch (frequency) {
     case PowerLineFrequency::FREQUENCY_50HZ:
@@ -34,6 +35,7 @@ int TranslatePowerLineFrequencyToV4L2(Po
       return V4L2_CID_POWER_LINE_FREQUENCY_AUTO;
   }
 }
+#endif
 
 }  // namespace
 
@@ -70,6 +72,7 @@ VideoCaptureDeviceLinux::~VideoCaptureDe
 void VideoCaptureDeviceLinux::AllocateAndStart(
     const VideoCaptureParams& params,
     std::unique_ptr<VideoCaptureDevice::Client> client) {
+#if !defined(OS_NETBSD)
   DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
   DCHECK(!capture_impl_);
   if (v4l2_thread_.IsRunning())
@@ -98,6 +101,7 @@ void VideoCaptureDeviceLinux::AllocateAn
   for (auto& request : photo_requests_queue_)
     v4l2_thread_.task_runner()->PostTask(FROM_HERE, std::move(request));
   photo_requests_queue_.clear();
+#endif
 }
 
 void VideoCaptureDeviceLinux::StopAndDeAllocate() {

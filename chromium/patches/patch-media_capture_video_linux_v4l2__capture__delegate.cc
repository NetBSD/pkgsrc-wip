$NetBSD$

--- media/capture/video/linux/v4l2_capture_delegate.cc.orig	2020-07-15 18:55:59.000000000 +0000
+++ media/capture/video/linux/v4l2_capture_delegate.cc
@@ -4,8 +4,12 @@
 
 #include "media/capture/video/linux/v4l2_capture_delegate.h"
 
+#if defined(OS_LINUX)
 #include <linux/version.h>
 #include <linux/videodev2.h>
+#else
+#include <sys/videoio.h>
+#endif
 #include <poll.h>
 #include <sys/fcntl.h>
 #include <sys/ioctl.h>
@@ -24,10 +28,12 @@
 
 using media::mojom::MeteringMode;
 
-#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0)
+#if defined(OS_LINUX)
+#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 6, 0) || defined(OS_BSD)
 // 16 bit depth, Realsense F200.
 #define V4L2_PIX_FMT_Z16 v4l2_fourcc('Z', '1', '6', ' ')
 #endif
+#endif
 
 // TODO(aleksandar.stojiljkovic): Wrap this with kernel version check once the
 // format is introduced to kernel.
@@ -66,8 +72,10 @@ struct {
   size_t num_planes;
 } constexpr kSupportedFormatsAndPlanarity[] = {
     {V4L2_PIX_FMT_YUV420, PIXEL_FORMAT_I420, 1},
+#if !defined(OS_NETBSD)
     {V4L2_PIX_FMT_Y16, PIXEL_FORMAT_Y16, 1},
     {V4L2_PIX_FMT_Z16, PIXEL_FORMAT_Y16, 1},
+#endif
     {V4L2_PIX_FMT_INVZ, PIXEL_FORMAT_Y16, 1},
     {V4L2_PIX_FMT_YUYV, PIXEL_FORMAT_YUY2, 1},
     {V4L2_PIX_FMT_RGB24, PIXEL_FORMAT_RGB24, 1},
@@ -86,11 +94,13 @@ struct {
 constexpr int kMaxIOCtrlRetries = 5;
 
 // Base id and class identifier for Controls to be reset.
+#if !defined(OS_NETBSD)
 struct {
   uint32_t control_base;
   uint32_t class_id;
 } constexpr kControls[] = {{V4L2_CID_USER_BASE, V4L2_CID_USER_CLASS},
                            {V4L2_CID_CAMERA_CLASS_BASE, V4L2_CID_CAMERA_CLASS}};
+#endif
 
 // Fill in |format| with the given parameters.
 void FillV4L2Format(v4l2_format* format,
@@ -123,9 +133,11 @@ void FillV4L2RequestBuffer(v4l2_requestb
 bool IsSpecialControl(int control_id) {
   switch (control_id) {
     case V4L2_CID_AUTO_WHITE_BALANCE:
+#if !defined(OS_NETBSD)
     case V4L2_CID_EXPOSURE_AUTO:
     case V4L2_CID_EXPOSURE_AUTO_PRIORITY:
     case V4L2_CID_FOCUS_AUTO:
+#endif
       return true;
   }
   return false;
@@ -142,6 +154,7 @@ bool IsSpecialControl(int control_id) {
 #define V4L2_CID_PANTILT_CMD (V4L2_CID_CAMERA_CLASS_BASE + 34)
 #endif
 bool IsBlacklistedControl(int control_id) {
+#if !defined(OS_NETBSD)
   switch (control_id) {
     case V4L2_CID_PAN_RELATIVE:
     case V4L2_CID_TILT_RELATIVE:
@@ -157,6 +170,7 @@ bool IsBlacklistedControl(int control_id
     case V4L2_CID_PANTILT_CMD:
       return true;
   }
+#endif
   return false;
 }
 
@@ -335,6 +349,7 @@ void V4L2CaptureDelegate::AllocateAndSta
 
   // Set anti-banding/anti-flicker to 50/60Hz. May fail due to not supported
   // operation (|errno| == EINVAL in this case) or plain failure.
+#if !defined(OS_NETBSD)
   if ((power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_50HZ) ||
       (power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_60HZ) ||
       (power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_AUTO)) {
@@ -345,6 +360,7 @@ void V4L2CaptureDelegate::AllocateAndSta
     if (retval != 0)
       DVLOG(1) << "Error setting power line frequency removal";
   }
+#endif
 
   capture_format_.frame_size.SetSize(video_fmt_.fmt.pix.width,
                                      video_fmt_.fmt.pix.height);
@@ -384,6 +400,7 @@ void V4L2CaptureDelegate::GetPhotoState(
 
   mojom::PhotoStatePtr photo_capabilities = mojo::CreateEmptyPhotoState();
 
+#if !defined(OS_NETBSD)
   photo_capabilities->pan = RetrieveUserControlRange(V4L2_CID_PAN_ABSOLUTE);
   photo_capabilities->tilt = RetrieveUserControlRange(V4L2_CID_TILT_ABSOLUTE);
   photo_capabilities->zoom = RetrieveUserControlRange(V4L2_CID_ZOOM_ABSOLUTE);
@@ -481,6 +498,7 @@ void V4L2CaptureDelegate::GetPhotoState(
   photo_capabilities->saturation =
       RetrieveUserControlRange(V4L2_CID_SATURATION);
   photo_capabilities->sharpness = RetrieveUserControlRange(V4L2_CID_SHARPNESS);
+#endif
 
   std::move(callback).Run(std::move(photo_capabilities));
 }
@@ -492,6 +510,7 @@ void V4L2CaptureDelegate::SetPhotoOption
   if (!device_fd_.is_valid() || !is_capturing_)
     return;
 
+#if !defined(OS_NETBSD)
   if (settings->has_pan) {
     v4l2_control pan_current = {};
     pan_current.id = V4L2_CID_PAN_ABSOLUTE;
@@ -603,6 +622,7 @@ void V4L2CaptureDelegate::SetPhotoOption
       DoIoctl(VIDIOC_S_CTRL, &set_exposure_time);
     }
   }
+#endif
 
   if (settings->has_brightness) {
     v4l2_control current = {};
@@ -686,6 +706,7 @@ mojom::RangePtr V4L2CaptureDelegate::Ret
 }
 
 void V4L2CaptureDelegate::ResetUserAndCameraControlsToDefault() {
+#if !defined(OS_NETBSD)
   // Set V4L2_CID_AUTO_WHITE_BALANCE to false first.
   v4l2_control auto_white_balance = {};
   auto_white_balance.id = V4L2_CID_AUTO_WHITE_BALANCE;
@@ -781,6 +802,7 @@ void V4L2CaptureDelegate::ResetUserAndCa
   ext_controls.controls = special_camera_controls.data();
   if (DoIoctl(VIDIOC_S_EXT_CTRLS, &ext_controls) < 0)
     DPLOG(INFO) << "VIDIOC_S_EXT_CTRLS";
+#endif
 }
 
 bool V4L2CaptureDelegate::MapAndQueueBuffer(int index) {

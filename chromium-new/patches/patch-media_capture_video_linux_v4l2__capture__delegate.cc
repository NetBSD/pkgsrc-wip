$NetBSD$

--- media/capture/video/linux/v4l2_capture_delegate.cc.orig	2016-06-24 01:02:23.000000000 +0000
+++ media/capture/video/linux/v4l2_capture_delegate.cc
@@ -248,6 +248,7 @@ void V4L2CaptureDelegate::AllocateAndSta
   // TODO(mcasas): what should be done if the camera driver does not allow
   // framerate configuration, or the actual one is different from the desired?
 
+#if !defined(__NetBSD__)
   // Set anti-banding/anti-flicker to 50/60Hz. May fail due to not supported
   // operation (|errno| == EINVAL in this case) or plain failure.
   if ((power_line_frequency_ == V4L2_CID_POWER_LINE_FREQUENCY_50HZ) ||
@@ -261,6 +262,7 @@ void V4L2CaptureDelegate::AllocateAndSta
     if (retval != 0)
       DVLOG(1) << "Error setting power line frequency removal";
   }
+#endif
 
   capture_format_.frame_size.SetSize(video_fmt_.fmt.pix.width,
                                      video_fmt_.fmt.pix.height);

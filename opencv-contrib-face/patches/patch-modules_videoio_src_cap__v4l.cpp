$NetBSD: patch-modules_videoio_src_cap__v4l.cpp,v 1.11 2025/07/07 05:15:26 wiz Exp $

Conditionalize settings not available in NetBSD's v4l2 emulation.
Avoid non-standard integer types.

--- modules/videoio/src/cap_v4l.cpp.orig	2026-06-05 18:50:05.000000000 +0000
+++ modules/videoio/src/cap_v4l.cpp
@@ -215,6 +215,14 @@ make & enjoy!
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <inttypes.h>
+#include <stdint.h>
+#ifndef __u32
+#define __u32 uint32_t
+#endif
+#ifndef __s32
+#define __s32 int32_t
+#endif
 #include <sys/types.h>
 #include <sys/mman.h>
 
@@ -241,24 +249,30 @@ typedef uint32_t __u32;
 #endif
 
 // https://github.com/opencv/opencv/issues/13335
+#ifdef V4L2_CID_CAMERA_CLASS_BASE
 #ifndef V4L2_CID_ISO_SENSITIVITY
 #define V4L2_CID_ISO_SENSITIVITY (V4L2_CID_CAMERA_CLASS_BASE+23)
 #endif
+#endif
 
 // https://github.com/opencv/opencv/issues/13929
+#ifdef V4L2_CID_MPEG_BASE
 #ifndef V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_HEIGHT
 #define V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_HEIGHT (V4L2_CID_MPEG_BASE+364)
 #endif
 #ifndef V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_WIDTH
 #define V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_WIDTH (V4L2_CID_MPEG_BASE+365)
 #endif
+#endif
 
 #ifndef V4L2_CID_ROTATE
 #define V4L2_CID_ROTATE (V4L2_CID_BASE+34)
 #endif
+#ifdef V4L2_CID_CAMERA_CLASS_BASE
 #ifndef V4L2_CID_IRIS_ABSOLUTE
 #define V4L2_CID_IRIS_ABSOLUTE (V4L2_CID_CAMERA_CLASS_BASE+17)
 #endif
+#endif
 
 #ifndef v4l2_fourcc_be
 #define v4l2_fourcc_be(a, b, c, d) (v4l2_fourcc(a, b, c, d) | (1U << 31))
@@ -1467,6 +1481,7 @@ void CvCaptureCAM_V4L::convertToRgb(const Buffer &curr
     case V4L2_PIX_FMT_RGB24:
         cv::cvtColor(cv::Mat(imageSize, CV_8UC3, start), frame, COLOR_RGB2BGR);
         return;
+#ifdef V4L2_PIX_FMT_Y16
     case V4L2_PIX_FMT_Y16:
     {
         // https://www.kernel.org/doc/html/v4.10/media/uapi/v4l/pixfmt-y16.html
@@ -1531,6 +1546,7 @@ void CvCaptureCAM_V4L::convertToRgb(const Buffer &curr
         cv::cvtColor(cv::Mat(imageSize, CV_8UC1, start), frame, COLOR_BayerGB2BGR);
         return;
     }
+#endif
     case V4L2_PIX_FMT_GREY:
         cv::cvtColor(cv::Mat(imageSize, CV_8UC1, start), frame, COLOR_GRAY2BGR);
         return;
@@ -1650,8 +1666,10 @@ static inline int capPropertyToV4L2(int prop)
         return CAP_PROP_UNKNOWN;
     case cv::CAP_PROP_FOURCC:
         return CAP_PROP_UNKNOWN;
+#ifdef V4L2_CID_MPEG_VIDEO_B_FRAMES
     case cv::CAP_PROP_FRAME_COUNT:
         return V4L2_CID_MPEG_VIDEO_B_FRAMES;
+#endif
     case cv::CAP_PROP_FORMAT:
         return CAP_PROP_UNKNOWN;
     case cv::CAP_PROP_MODE:
@@ -1666,8 +1684,10 @@ static inline int capPropertyToV4L2(int prop)
         return V4L2_CID_HUE;
     case cv::CAP_PROP_GAIN:
         return V4L2_CID_GAIN;
+#ifdef V4L2_CID_EXPOSURE_ABSOLUTE
     case cv::CAP_PROP_EXPOSURE:
         return V4L2_CID_EXPOSURE_ABSOLUTE;
+#endif
     case cv::CAP_PROP_CONVERT_RGB:
         return CAP_PROP_UNKNOWN;
     case cv::CAP_PROP_WHITE_BALANCE_BLUE_U:
@@ -1678,8 +1698,10 @@ static inline int capPropertyToV4L2(int prop)
         return CAP_PROP_UNKNOWN;
     case cv::CAP_PROP_SHARPNESS:
         return V4L2_CID_SHARPNESS;
+#ifdef V4L2_CID_EXPOSURE_AUTO
     case cv::CAP_PROP_AUTO_EXPOSURE:
         return V4L2_CID_EXPOSURE_AUTO;
+#endif
     case cv::CAP_PROP_GAMMA:
         return V4L2_CID_GAMMA;
     case cv::CAP_PROP_TEMPERATURE:

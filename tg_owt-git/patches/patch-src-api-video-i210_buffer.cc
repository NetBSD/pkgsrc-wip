$NetBSD$

Stub I210Copy/I422ToI210/I210Rotate/I210ToI420/I422Scale_16 — not in system libyuv.

--- src/api/video/i210_buffer.cc.orig
+++ src/api/video/i210_buffer.cc
@@ -9,6 +9,7 @@
  */
 #include "api/video/i210_buffer.h"
 
+#include <cstring>
 #include <utility>
 
 #include "api/make_ref_counted.h"
@@ -67,12 +68,9 @@
   const int width = source.width();
   const int height = source.height();
   rtc::scoped_refptr<I210Buffer> buffer = Create(width, height);
-  RTC_CHECK_EQ(
-      0, libyuv::I210Copy(
-             source.DataY(), source.StrideY(), source.DataU(), source.StrideU(),
-             source.DataV(), source.StrideV(), buffer->MutableDataY(),
-             buffer->StrideY(), buffer->MutableDataU(), buffer->StrideU(),
-             buffer->MutableDataV(), buffer->StrideV(), width, height));
+  memset(buffer->MutableDataY(), 0, width * 2 * height);
+  memset(buffer->MutableDataU(), 0, ((width + 1) / 2) * 2 * height);
+  memset(buffer->MutableDataV(), 0, ((width + 1) / 2) * 2 * height);
   return buffer;
 }
 
@@ -83,13 +81,9 @@
   const int height = source.height();
   auto i422buffer = I422Buffer::Copy(source);
   rtc::scoped_refptr<I210Buffer> buffer = Create(width, height);
-  RTC_CHECK_EQ(0, libyuv::I422ToI210(i422buffer->DataY(), i422buffer->StrideY(),
-                                     i422buffer->DataU(), i422buffer->StrideU(),
-                                     i422buffer->DataV(), i422buffer->StrideV(),
-                                     buffer->MutableDataY(), buffer->StrideY(),
-                                     buffer->MutableDataU(), buffer->StrideU(),
-                                     buffer->MutableDataV(), buffer->StrideV(),
-                                     width, height));
+  memset(buffer->MutableDataY(), 0, width * 2 * height);
+  memset(buffer->MutableDataU(), 0, ((width + 1) / 2) * 2 * height);
+  memset(buffer->MutableDataV(), 0, ((width + 1) / 2) * 2 * height);
   return buffer;
 }
 
@@ -111,25 +105,15 @@
   rtc::scoped_refptr<webrtc::I210Buffer> buffer =
       I210Buffer::Create(rotated_width, rotated_height);
 
-  RTC_CHECK_EQ(0,
-               libyuv::I210Rotate(
-                   src.DataY(), src.StrideY(), src.DataU(), src.StrideU(),
-                   src.DataV(), src.StrideV(), buffer->MutableDataY(),
-                   buffer->StrideY(), buffer->MutableDataU(), buffer->StrideU(),
-                   buffer->MutableDataV(), buffer->StrideV(), src.width(),
-                   src.height(), static_cast<libyuv::RotationMode>(rotation)));
-
-  return buffer;
+  return Copy(src);
 }
 
 rtc::scoped_refptr<I420BufferInterface> I210Buffer::ToI420() {
   rtc::scoped_refptr<I420Buffer> i420_buffer =
       I420Buffer::Create(width(), height());
-  libyuv::I210ToI420(DataY(), StrideY(), DataU(), StrideU(), DataV(), StrideV(),
-                     i420_buffer->MutableDataY(), i420_buffer->StrideY(),
-                     i420_buffer->MutableDataU(), i420_buffer->StrideU(),
-                     i420_buffer->MutableDataV(), i420_buffer->StrideV(),
-                     width(), height());
+  memset(i420_buffer->MutableDataY(), 0, width() * height());
+  memset(i420_buffer->MutableDataU(), 0, ((width() + 1) / 2) * ((height() + 1) / 2));
+  memset(i420_buffer->MutableDataV(), 0, ((width() + 1) / 2) * ((height() + 1) / 2));
   return i420_buffer;
 }
 
@@ -195,13 +179,9 @@
       src.DataU() + src.StrideU() * uv_offset_y + uv_offset_x;
   const uint16_t* v_plane =
       src.DataV() + src.StrideV() * uv_offset_y + uv_offset_x;
-  int res = libyuv::I422Scale_16(
-      y_plane, src.StrideY(), u_plane, src.StrideU(), v_plane, src.StrideV(),
-      crop_width, crop_height, MutableDataY(), StrideY(), MutableDataU(),
-      StrideU(), MutableDataV(), StrideV(), width(), height(),
-      libyuv::kFilterBox);
-
-  RTC_DCHECK_EQ(res, 0);
+  memset(MutableDataY(), 0, width() * 2 * height());
+  memset(MutableDataU(), 0, ((width() + 1) / 2) * 2 * height());
+  memset(MutableDataV(), 0, ((width() + 1) / 2) * 2 * height());
 }
 
 void I210Buffer::ScaleFrom(const I210BufferInterface& src) {

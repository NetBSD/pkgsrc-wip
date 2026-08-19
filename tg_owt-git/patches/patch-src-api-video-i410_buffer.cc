$NetBSD$

Stub I410Copy/I410ToI420/I410Rotate — not in system libyuv.

--- src/api/video/i410_buffer.cc.orig
+++ src/api/video/i410_buffer.cc
@@ -12,6 +12,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstring>
 #include <utility>
 
 #include "api/make_ref_counted.h"
@@ -95,12 +96,9 @@
                                                 int stride_v) {
   // Note: May use different strides than the input data.
   rtc::scoped_refptr<I410Buffer> buffer = Create(width, height);
-  int res = libyuv::I410Copy(data_y, stride_y, data_u, stride_u, data_v,
-                             stride_v, buffer->MutableDataY(),
-                             buffer->StrideY(), buffer->MutableDataU(),
-                             buffer->StrideU(), buffer->MutableDataV(),
-                             buffer->StrideV(), width, height);
-  RTC_DCHECK_EQ(res, 0);
+  memset(buffer->MutableDataY(), 0, width * 2 * height);
+  memset(buffer->MutableDataU(), 0, width * 2 * height);
+  memset(buffer->MutableDataV(), 0, width * 2 * height);
 
   return buffer;
 }
@@ -123,26 +121,15 @@
   rtc::scoped_refptr<webrtc::I410Buffer> buffer =
       I410Buffer::Create(rotated_width, rotated_height);
 
-  int res = libyuv::I410Rotate(
-      src.DataY(), src.StrideY(), src.DataU(), src.StrideU(), src.DataV(),
-      src.StrideV(), buffer->MutableDataY(), buffer->StrideY(),
-      buffer->MutableDataU(), buffer->StrideU(), buffer->MutableDataV(),
-      buffer->StrideV(), src.width(), src.height(),
-      static_cast<libyuv::RotationMode>(rotation));
-  RTC_DCHECK_EQ(res, 0);
-
-  return buffer;
+  return Copy(src);
 }
 
 rtc::scoped_refptr<I420BufferInterface> I410Buffer::ToI420() {
   rtc::scoped_refptr<I420Buffer> i420_buffer =
       I420Buffer::Create(width(), height());
-  int res = libyuv::I410ToI420(
-      DataY(), StrideY(), DataU(), StrideU(), DataV(), StrideV(),
-      i420_buffer->MutableDataY(), i420_buffer->StrideY(),
-      i420_buffer->MutableDataU(), i420_buffer->StrideU(),
-      i420_buffer->MutableDataV(), i420_buffer->StrideV(), width(), height());
-  RTC_DCHECK_EQ(res, 0);
+  memset(i420_buffer->MutableDataY(), 0, width() * height());
+  memset(i420_buffer->MutableDataU(), 0, ((width() + 1) / 2) * ((height() + 1) / 2));
+  memset(i420_buffer->MutableDataV(), 0, ((width() + 1) / 2) * ((height() + 1) / 2));
 
   return i420_buffer;
 }

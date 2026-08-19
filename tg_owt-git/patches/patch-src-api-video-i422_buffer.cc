$NetBSD$

Stub I422Rotate/I422Scale — not in system libyuv.

--- src/api/video/i422_buffer.cc.orig
+++ src/api/video/i422_buffer.cc
@@ -12,6 +12,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstring>
 #include <utility>
 
 #include "api/make_ref_counted.h"
@@ -136,15 +137,7 @@
   rtc::scoped_refptr<webrtc::I422Buffer> buffer =
       I422Buffer::Create(rotated_width, rotated_height);
 
-  int res = libyuv::I422Rotate(
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
 
 rtc::scoped_refptr<I420BufferInterface> I422Buffer::ToI420() {
@@ -226,12 +219,9 @@
   const uint8_t* v_plane =
       src.DataV() + src.StrideV() * uv_offset_y + uv_offset_x;
 
-  int res =
-      libyuv::I422Scale(y_plane, src.StrideY(), u_plane, src.StrideU(), v_plane,
-                        src.StrideV(), crop_width, crop_height, MutableDataY(),
-                        StrideY(), MutableDataU(), StrideU(), MutableDataV(),
-                        StrideV(), width(), height(), libyuv::kFilterBox);
-  RTC_DCHECK_EQ(res, 0);
+  memset(MutableDataY(), 0, width() * height());
+  memset(MutableDataU(), 0, ((width() + 1) / 2) * height());
+  memset(MutableDataV(), 0, ((width() + 1) / 2) * height());
 }
 
 }  // namespace webrtc

$NetBSD$

Stub I010Rotate — not present in system libyuv.

--- src/api/video/i010_buffer.cc.orig
+++ src/api/video/i010_buffer.cc
@@ -112,15 +112,7 @@
   rtc::scoped_refptr<webrtc::I010Buffer> buffer =
       Create(rotated_width, rotated_height);
 
-  int res = libyuv::I010Rotate(
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
 
 rtc::scoped_refptr<I420BufferInterface> I010Buffer::ToI420() {

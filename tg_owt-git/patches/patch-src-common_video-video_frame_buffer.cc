$NetBSD$

Stub I210ToI420/I410ToI420 — not in system libyuv.

--- src/common_video/video_frame_buffer.cc.orig
+++ src/common_video/video_frame_buffer.cc
@@ -12,7 +12,8 @@
 #include "api/make_ref_counted.h"
 #include "api/video/i420_buffer.h"
 #include "rtc_base/checks.h"
-#include "third_party/libyuv/include/libyuv/convert.h"
+#include <cstring>
+#include <libyuv/convert.h>
 
 namespace webrtc {
 
@@ -219,11 +220,9 @@
 rtc::scoped_refptr<I420BufferInterface> I210BufferBase::ToI420() {
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
 
@@ -235,11 +234,9 @@
 rtc::scoped_refptr<I420BufferInterface> I410BufferBase::ToI420() {
   rtc::scoped_refptr<I420Buffer> i420_buffer =
       I420Buffer::Create(width(), height());
-  libyuv::I410ToI420(DataY(), StrideY(), DataU(), StrideU(), DataV(), StrideV(),
-                     i420_buffer->MutableDataY(), i420_buffer->StrideY(),
-                     i420_buffer->MutableDataU(), i420_buffer->StrideU(),
-                     i420_buffer->MutableDataV(), i420_buffer->StrideV(),
-                     width(), height());
+  memset(i420_buffer->MutableDataY(), 0, width() * height());
+  memset(i420_buffer->MutableDataU(), 0, ((width() + 1) / 2) * ((height() + 1) / 2));
+  memset(i420_buffer->MutableDataV(), 0, ((width() + 1) / 2) * ((height() + 1) / 2));
   return i420_buffer;
 }
 

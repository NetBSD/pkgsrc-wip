$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/gin_converters/osr_converter.cc.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/shell/common/gin_converters/osr_converter.cc
@@ -117,7 +117,7 @@ v8::Local<v8::Value> Converter<electron:
           const_cast<uintptr_t*>(&val.shared_texture_handle)),
       sizeof(val.shared_texture_handle));
   dict.Set("sharedTextureHandle", handle_buf.ToLocalChecked());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto v8_planes = base::ToVector(val.planes, [isolate](const auto& plane) {
     gin::Dictionary v8_plane(isolate, v8::Object::New(isolate));
     v8_plane.Set("stride", plane.stride);

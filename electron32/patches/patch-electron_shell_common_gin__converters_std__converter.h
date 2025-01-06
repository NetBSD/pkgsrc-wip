$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/gin_converters/std_converter.h.orig	2024-12-05 00:03:24.000000000 +0000
+++ electron/shell/common/gin_converters/std_converter.h
@@ -28,7 +28,7 @@ v8::Local<v8::Value> ConvertToV8(v8::Iso
       isolate, std::forward<T>(input));
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 template <>
 struct Converter<unsigned long> {  // NOLINT(runtime/int)
   static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,

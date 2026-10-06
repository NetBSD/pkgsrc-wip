$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/gin_converters/std_converter.h.orig	2025-05-09 16:52:15.000000000 +0000
+++ electron/shell/common/gin_converters/std_converter.h
@@ -57,7 +57,7 @@ struct Converter<std::array<T, N>> {
   }
 };
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 template <>
 struct Converter<unsigned long> {  // NOLINT(runtime/int)
   static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,

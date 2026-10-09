$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- electron/shell/common/api/electron_api_native_image.cc.orig	2026-10-06 22:48:58.000000000 +0000
+++ electron/shell/common/api/electron_api_native_image.cc
@@ -676,7 +676,7 @@ void Initialize(v8::Local<v8::Object> ex
   native_image.SetMethod("createFromNamedImage",
                          &NativeImage::CreateFromNamedImage);
   native_image.SetMethod("createMenuSymbol", &NativeImage::CreateMenuSymbol);
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   native_image.SetMethod("createThumbnailFromPath",
                          &NativeImage::CreateThumbnailFromPath);
 #endif

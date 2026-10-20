$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, 
  FreeBSD's electron patches, and pkgsrc's nodejs patches

--- electron/shell/common/api/electron_api_native_image.h.orig	2026-10-16 03:32:58.000000000 +0000
+++ electron/shell/common/api/electron_api_native_image.h
@@ -73,7 +73,7 @@ class NativeImage final : public gin::Wr
   static NativeImage* CreateFromNamedImage(gin::Arguments* args,
                                            std::string name);
   static NativeImage* CreateMenuSymbol(gin::Arguments* args, std::string name);
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   static v8::Local<v8::Promise> CreateThumbnailFromPath(
       v8::Isolate* isolate,
       const base::FilePath& path,

$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/client/test_shared_image_interface.h.orig	2026-04-28 23:05:57.000000000 +0200
+++ gpu/command_buffer/client/test_shared_image_interface.h
@@ -136,7 +136,7 @@ class TestSharedImageInterface : public 
       bool premapped,
       const ClientSharedImage::AsyncMapInvokedCallback& callback);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // Creates a mappable SI backed by a NativePixmapHandle.
   scoped_refptr<ClientSharedImage> CreateNativePixmapBackedSharedImage(
       const SharedImageInfo& si_info,

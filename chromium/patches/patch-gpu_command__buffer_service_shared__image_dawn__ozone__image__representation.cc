$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_image/dawn_ozone_image_representation.cc.orig	2026-06-23 23:37:18.000000000 +0000
+++ gpu/command_buffer/service/shared_image/dawn_ozone_image_representation.cc
@@ -194,6 +194,7 @@ void DawnOzoneImageRepresentation::EndAc
   if (!texture_) {
     return;
   }
+#if 0
   wgpu::SharedTextureMemoryEndAccessState end_access_desc = {};
   wgpu::SharedTextureMemoryVkImageLayoutEndState end_layout{};
   end_access_desc.nextInChain = &end_layout;
@@ -243,6 +244,12 @@ void DawnOzoneImageRepresentation::EndAc
 
   texture_.Destroy();
   texture_ = nullptr;
+#else
+    LOG(ERROR) << "Failed to end access for DawnOzoneImageRepresentation";
+    texture_.Destroy();
+    texture_ = nullptr;
+    return;
+#endif
 }
 
 }  // namespace gpu

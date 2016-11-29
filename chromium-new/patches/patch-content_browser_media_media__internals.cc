$NetBSD$

--- content/browser/media/media_internals.cc.orig	2016-11-10 20:02:14.000000000 +0000
+++ content/browser/media/media_internals.cc
@@ -724,7 +724,7 @@ void MediaInternals::UpdateVideoCaptureD
     device_dict->SetString("name", descriptor.GetNameAndModel());
     device_dict->Set("formats", format_list);
 #if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || \
-    defined(OS_ANDROID)
+    defined(OS_ANDROID) || defined(OS_BSD)
     device_dict->SetString("captureApi", descriptor.GetCaptureApiTypeString());
 #endif
     video_capture_capabilities_cached_data_.Append(std::move(device_dict));

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/webrtc/native_desktop_media_list.cc.orig	2024-10-18 12:34:01.701188800 +0000
+++ chrome/browser/media/webrtc/native_desktop_media_list.cc
@@ -171,7 +171,7 @@ BOOL CALLBACK AllHwndCollector(HWND hwnd
 #if BUILDFLAG(IS_MAC)
 BASE_FEATURE(kWindowCaptureMacV2,
              "WindowCaptureMacV2",
-             base::FEATURE_ENABLED_BY_DEFAULT);
+             base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
 content::DesktopMediaID::Type ConvertToDesktopMediaIDType(
@@ -356,7 +356,7 @@ class NativeDesktopMediaList::Worker
   base::WeakPtr<NativeDesktopMediaList> media_list_;
 
   DesktopMediaID::Type source_type_;
-  const std::unique_ptr<ThumbnailCapturer> capturer_;
+  std::unique_ptr<ThumbnailCapturer> capturer_;
   const ThumbnailCapturer::FrameDeliveryMethod frame_delivery_method_;
   const bool add_current_process_windows_;
 
@@ -644,6 +644,12 @@ void NativeDesktopMediaList::Worker::Ref
       FROM_HERE,
       base::BindOnce(&NativeDesktopMediaList::UpdateNativeThumbnailsFinished,
                      media_list_));
+
+  // This call is necessary to release underlying OS screen capture mechanisms.
+  // Skip if the source list is delegated, as the source list window will be active.
+  if (!capturer_->GetDelegatedSourceListController()) {
+    capturer_.reset();
+  }
 }
 
 void NativeDesktopMediaList::Worker::OnCaptureResult(
@@ -1028,6 +1034,11 @@ void NativeDesktopMediaList::RefreshForV
         FROM_HERE, base::BindOnce(&Worker::RefreshThumbnails,
                                   base::Unretained(worker_.get()),
                                   std::move(native_ids), thumbnail_size_));
+  } else {
+#if defined(USE_AURA)
+    pending_native_thumbnail_capture_ = true;
+#endif
+    UpdateNativeThumbnailsFinished();
   }
 }
 

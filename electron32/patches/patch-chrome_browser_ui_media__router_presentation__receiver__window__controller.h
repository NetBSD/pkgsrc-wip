$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/media_router/presentation_receiver_window_controller.h.orig	2024-10-18 12:34:03.176370600 +0000
+++ chrome/browser/ui/media_router/presentation_receiver_window_controller.h
@@ -105,8 +105,7 @@ class PresentationReceiverWindowControll
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override;
+      const content::mojom::CreateNewWindowParams& params) override;
 
   // The profile used for the presentation.
   raw_ptr<Profile, DanglingUntriaged> otr_profile_;

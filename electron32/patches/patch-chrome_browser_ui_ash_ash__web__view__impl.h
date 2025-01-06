$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/ash/ash_web_view_impl.h.orig	2024-10-18 12:34:03.100412400 +0000
+++ chrome/browser/ui/ash/ash_web_view_impl.h
@@ -59,8 +59,7 @@ class AshWebViewImpl : public ash::AshWe
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override;
+      const content::mojom::CreateNewWindowParams& params) override;
   content::WebContents* OpenURLFromTab(
       content::WebContents* source,
       const content::OpenURLParams& params,

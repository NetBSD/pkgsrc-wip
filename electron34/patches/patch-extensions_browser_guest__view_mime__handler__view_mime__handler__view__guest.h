$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/browser/guest_view/mime_handler_view/mime_handler_view_guest.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ extensions/browser/guest_view/mime_handler_view/mime_handler_view_guest.h
@@ -181,8 +181,7 @@ class MimeHandlerViewGuest
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override;
+      const content::mojom::CreateNewWindowParams& params) override;
   content::WebContents* CreateCustomWebContents(
       content::RenderFrameHost* opener,
       content::SiteInstance* source_site_instance,

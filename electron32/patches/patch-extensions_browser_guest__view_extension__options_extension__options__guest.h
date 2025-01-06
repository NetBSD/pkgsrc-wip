$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/browser/guest_view/extension_options/extension_options_guest.h.orig	2024-10-18 12:34:17.836640000 +0000
+++ extensions/browser/guest_view/extension_options/extension_options_guest.h
@@ -65,8 +65,7 @@ class ExtensionOptionsGuest
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) final;
+      const content::mojom::CreateNewWindowParams& params) final;
   content::WebContents* CreateCustomWebContents(
       content::RenderFrameHost* opener,
       content::SiteInstance* source_site_instance,

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/browser/guest_view/extension_options/extension_options_guest.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ extensions/browser/guest_view/extension_options/extension_options_guest.h
@@ -70,8 +70,7 @@ class ExtensionOptionsGuest
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) final;
+      const content::mojom::CreateNewWindowParams& params) final;
   content::WebContents* CreateCustomWebContents(
       content::RenderFrameHost* opener,
       content::SiteInstance* source_site_instance,

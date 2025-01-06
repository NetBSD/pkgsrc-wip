$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- fuchsia_web/webengine/browser/frame_impl.h.orig	2024-10-18 12:34:18.320396400 +0000
+++ fuchsia_web/webengine/browser/frame_impl.h
@@ -306,8 +306,7 @@ class WEB_ENGINE_EXPORT FrameImpl : publ
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override;
+      const content::mojom::CreateNewWindowParams& params) override;
   void WebContentsCreated(content::WebContents* source_contents,
                           int opener_render_process_id,
                           int opener_render_frame_id,

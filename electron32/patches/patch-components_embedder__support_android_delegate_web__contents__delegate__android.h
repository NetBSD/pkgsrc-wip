$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/embedder_support/android/delegate/web_contents_delegate_android.h.orig	2024-10-18 12:34:06.690452800 +0000
+++ components/embedder_support/android/delegate/web_contents_delegate_android.h
@@ -82,8 +82,7 @@ class WebContentsDelegateAndroid : publi
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override;
+      const content::mojom::CreateNewWindowParams& params) override;
   void CloseContents(content::WebContents* source) override;
   void SetContentsBounds(content::WebContents* source,
                          const gfx::Rect& bounds) override;

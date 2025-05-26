$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/media/offscreen_tab.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/media/offscreen_tab.h
@@ -107,8 +107,7 @@ class OffscreenTab final : public Profil
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) final;
+      const content::mojom::CreateNewWindowParams& params) override;
   void EnterFullscreenModeForTab(
       content::RenderFrameHost* requesting_frame,
       const blink::mojom::FullscreenOptions& options) final;

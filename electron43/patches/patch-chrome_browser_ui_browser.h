$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/browser.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ chrome/browser/ui/browser.h
@@ -301,7 +301,7 @@ class Browser : public TabStripModelObse
     std::optional<int64_t> display_id;
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // When the browser window is shown, the desktop environment is notified
     // using this ID.  In response, the desktop will stop playing the "waiting
     // for startup" animation (if any).
@@ -975,8 +975,7 @@ class Browser : public TabStripModelObse
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override;
+      const content::mojom::CreateNewWindowParams& params) override;
   content::WebContents* CreateCustomWebContents(
       content::RenderFrameHost* opener,
       content::SiteInstance* source_site_instance,

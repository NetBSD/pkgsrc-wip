$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- headless/lib/browser/headless_web_contents_impl.cc.orig	2024-10-18 12:34:18.956076900 +0000
+++ headless/lib/browser/headless_web_contents_impl.cc
@@ -62,7 +62,7 @@ namespace headless {
 namespace {
 
 void UpdatePrefsFromSystemSettings(blink::RendererPreferences* prefs) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
@@ -195,8 +195,7 @@ class HeadlessWebContentsImpl::Delegate 
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) override {
+      const content::mojom::CreateNewWindowParams& params) override {
     return headless_web_contents_->browser_context()
         ->options()
         ->block_new_web_contents();

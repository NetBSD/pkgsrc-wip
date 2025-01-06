$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- chrome/browser/ui/ash/ash_web_view_impl.cc.orig	2024-10-18 12:34:03.100412400 +0000
+++ chrome/browser/ui/ash/ash_web_view_impl.cc
@@ -118,10 +118,9 @@ bool AshWebViewImpl::IsWebContentsCreati
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   if (params_.suppress_navigation) {
-    NotifyDidSuppressNavigation(target_url,
+    NotifyDidSuppressNavigation(params.target_url,
                                 WindowOpenDisposition::NEW_FOREGROUND_TAB,
                                 /*from_user_gesture=*/true);
     return true;

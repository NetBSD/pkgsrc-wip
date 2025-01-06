$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- fuchsia_web/webengine/browser/frame_impl.cc.orig	2024-10-18 12:34:18.320396400 +0000
+++ fuchsia_web/webengine/browser/frame_impl.cc
@@ -574,8 +574,7 @@ bool FrameImpl::IsWebContentsCreationOve
     content::SiteInstance* source_site_instance,
     content::mojom::WindowContainerType window_container_type,
     const GURL& opener_url,
-    const std::string& frame_name,
-    const GURL& target_url) {
+    const content::mojom::CreateNewWindowParams& params) {
   // Specify a generous upper bound for unacknowledged popup windows, so that we
   // can catch bad client behavior while not interfering with normal operation.
   constexpr size_t kMaxPendingWebContentsCount = 10;

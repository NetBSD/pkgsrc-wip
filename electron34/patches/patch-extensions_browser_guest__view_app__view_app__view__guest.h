$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- extensions/browser/guest_view/app_view/app_view_guest.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ extensions/browser/guest_view/app_view/app_view_guest.h
@@ -10,6 +10,7 @@
 #include "base/containers/id_map.h"
 #include "base/values.h"
 #include "components/guest_view/browser/guest_view.h"
+#include "content/common/frame.mojom-shared.h"
 #include "extensions/browser/guest_view/app_view/app_view_guest_delegate.h"
 #include "extensions/browser/lazy_context_task_queue.h"
 
@@ -77,8 +78,7 @@ class AppViewGuest : public guest_view::
       content::SiteInstance* source_site_instance,
       content::mojom::WindowContainerType window_container_type,
       const GURL& opener_url,
-      const std::string& frame_name,
-      const GURL& target_url) final;
+      const content::mojom::CreateNewWindowParams& params) final;
   content::WebContents* CreateCustomWebContents(
       content::RenderFrameHost* opener,
       content::SiteInstance* source_site_instance,

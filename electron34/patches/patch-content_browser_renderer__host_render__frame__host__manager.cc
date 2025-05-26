$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_frame_host_manager.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/renderer_host/render_frame_host_manager.cc
@@ -4617,6 +4617,9 @@ RenderFrameHostManager::GetSiteInstanceF
     request->ResetStateForSiteInstanceChange();
   }
 
+  GetContentClient()->browser()->RegisterPendingSiteInstance(
+      render_frame_host_.get(), dest_site_instance.get());
+
   return dest_site_instance;
 }
 

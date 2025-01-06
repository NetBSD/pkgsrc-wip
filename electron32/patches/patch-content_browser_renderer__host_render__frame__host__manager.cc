$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_frame_host_manager.cc.orig	2024-10-18 12:34:13.546831400 +0000
+++ content/browser/renderer_host/render_frame_host_manager.cc
@@ -4470,6 +4470,9 @@ RenderFrameHostManager::GetSiteInstanceF
     request->ResetStateForSiteInstanceChange();
   }
 
+  GetContentClient()->browser()->RegisterPendingSiteInstance(
+      render_frame_host_.get(), dest_site_instance.get());
+
   return dest_site_instance;
 }
 

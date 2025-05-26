$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/web_contents/web_contents_view_drag_security_info.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/browser/web_contents/web_contents_view_drag_security_info.cc
@@ -66,7 +66,7 @@ bool WebContentsViewDragSecurityInfo::Is
   // browser-side checks only have local tree fragment (potentially with
   // multiple origins) granularity at best, but a drag operation eventually
   // targets one single frame in that local tree fragment.
-  return target_rwh->GetSiteInstanceGroup()->GetId() == site_instance_group_id_;
+  return true;
 }
 
 }  // namespace content

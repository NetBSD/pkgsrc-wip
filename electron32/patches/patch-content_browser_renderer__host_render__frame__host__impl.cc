$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/renderer_host/render_frame_host_impl.cc.orig	2024-10-18 12:34:13.514847800 +0000
+++ content/browser/renderer_host/render_frame_host_impl.cc
@@ -785,8 +785,8 @@ void VerifyThatBrowserAndRendererCalcula
   // TODO(crbug.com/40092527): Consider adding a separate boolean that
   // tracks this instead of piggybacking `origin_calculation_debug_info`.
   if (renderer_side_origin.opaque() &&
-      browser_side_origin_and_debug_info.first->opaque() &&
-      params.origin_calculation_debug_info.ends_with("is_newly_created")) {
+      browser_side_origin_and_debug_info.first->opaque() /*&&
+      params.origin_calculation_debug_info.ends_with("is_newly_created")*/) {
     origins_match = (renderer_side_origin.GetTupleOrPrecursorTupleIfOpaque() ==
                      browser_side_origin_and_debug_info.first
                          ->GetTupleOrPrecursorTupleIfOpaque());
@@ -7979,6 +7979,17 @@ void RenderFrameHostImpl::EnterFullscree
     }
   }
 
+  // Entering fullscreen from webview should also notify its outer frame.
+  if (frame_tree_node()->render_manager()->IsMainFrameForInnerDelegate()) {
+    RenderFrameProxyHost* outer_proxy =
+        frame_tree_node()->render_manager()->GetProxyToOuterDelegate();
+    DCHECK(outer_proxy);
+    if (outer_proxy->is_render_frame_proxy_live()) {
+      outer_proxy->GetAssociatedRemoteFrame()->WillEnterFullscreen(
+          options.Clone());
+    }
+  }
+
   // Focus the window if another frame may have delegated the capability.
   if (had_fullscreen_token && !GetView()->HasFocus())
     GetView()->Focus();
@@ -8832,6 +8843,7 @@ void RenderFrameHostImpl::CreateNewWindo
           last_committed_origin_, params->window_container_type,
           params->target_url, params->referrer.To<Referrer>(),
           params->frame_name, params->disposition, *params->features,
+          params->raw_features, params->body,
           effective_transient_activation_state, params->opener_suppressed,
           &no_javascript_access);
 

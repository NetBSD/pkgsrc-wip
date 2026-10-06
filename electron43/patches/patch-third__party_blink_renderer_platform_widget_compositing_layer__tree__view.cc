$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/platform/widget/compositing/layer_tree_view.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/platform/widget/compositing/layer_tree_view.cc
@@ -387,9 +387,13 @@ void LayerTreeView::DidFailToInitializeL
   // unable to be killed after Chrome is closed.
   // https://issues.chromium.org/336164423
   if (!Platform::Current()->IsGpuRemoteDisconnected()) {
-    layer_tree_host_->GetTaskRunnerProvider()->MainThreadTaskRunner()->PostTask(
+    // CompositingModeFallbackToSoftware IPC will disable GPU compositing in
+    // RenderThread. Post task with delay to give time to receive this IPC and
+    // prevent infinite loop of retries for software renderers.
+    // https://issues.chromium.org/345275130
+    layer_tree_host_->GetTaskRunnerProvider()->MainThreadTaskRunner()->PostDelayedTask(
         FROM_HERE, base::BindOnce(&LayerTreeView::RequestNewLayerTreeFrameSink,
-                                  weak_factory_.GetWeakPtr()));
+                                  weak_factory_.GetWeakPtr()), base::Milliseconds(10));
   }
 }
 

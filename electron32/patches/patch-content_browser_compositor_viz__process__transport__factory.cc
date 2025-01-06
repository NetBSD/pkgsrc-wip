$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/browser/compositor/viz_process_transport_factory.cc.orig	2024-10-18 12:34:12.279489300 +0000
+++ content/browser/compositor/viz_process_transport_factory.cc
@@ -110,7 +110,7 @@ class HostDisplayClient : public viz::Ho
   HostDisplayClient& operator=(const HostDisplayClient&) = delete;
 
   // viz::HostDisplayClient:
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
   void DidCompleteSwapWithNewSize(const gfx::Size& size) override {
     compositor_->OnCompleteSwapWithNewSize(size);
   }
@@ -390,8 +390,14 @@ void VizProcessTransportFactory::OnEstab
   mojo::AssociatedRemote<viz::mojom::DisplayPrivate> display_private;
   root_params->display_private =
       display_private.BindNewEndpointAndPassReceiver();
-  compositor_data.display_client =
-      std::make_unique<HostDisplayClient>(compositor);
+  if (compositor->delegate()) {
+    compositor_data.display_client = compositor->delegate()->CreateHostDisplayClient(
+        compositor);
+    root_params->offscreen = compositor->delegate()->IsOffscreen();
+  } else {
+    compositor_data.display_client =
+        std::make_unique<HostDisplayClient>(compositor);
+  }
   root_params->display_client =
       compositor_data.display_client->GetBoundRemote(resize_task_runner_);
   mojo::AssociatedRemote<viz::mojom::ExternalBeginFrameController>

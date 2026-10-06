$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- content/renderer/render_process_impl.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ content/renderer/render_process_impl.cc
@@ -200,6 +200,9 @@ RenderProcessImpl::RenderProcessImpl()
     v8::V8::SetFlagsFromString(kSABPerContextFlag, sizeof(kSABPerContextFlag));
   }
 
+  // Freezing flags after init conflicts with node in the renderer.
+  v8::V8::SetFlagsFromString("--no-freeze-flags-after-init");
+
   if (base::FeatureList::IsEnabled(features::kWebAssemblyTrapHandler)) {
     content::GetContentClient()->renderer()->SetUpWebAssemblyTrapHandler();
   }

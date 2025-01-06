$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/core/loader/modulescript/module_script_loader.cc.orig	2024-10-18 12:34:35.548117900 +0000
+++ third_party/blink/renderer/core/loader/modulescript/module_script_loader.cc
@@ -153,12 +153,20 @@ void ModuleScriptLoader::FetchInternal(
   url_ = module_request.Url();
 #endif
 
+  DOMWrapperWorld& request_world = modulator_->GetScriptState()->World();
+
+  // Prevents web service workers from intercepting isolated world dynamic
+  // script imports requests and responding with different contents.
+  // TODO(crbug.com/1296102): Link to documentation that describes the criteria
+  // where module imports are handled by service worker fetch handler.
+  resource_request.SetSkipServiceWorker(request_world.IsIsolatedWorld());
+
   // <spec step="9">Set request 's destination to the result of running the
   // fetch destination from module type steps given destination and
   // moduleType.</spec>
   SetFetchDestinationFromModuleType(resource_request, module_request);
 
-  ResourceLoaderOptions options(&modulator_->GetScriptState()->World());
+  ResourceLoaderOptions options(&request_world);
 
   // <spec step="11">Set request's initiator type to "script".</spec>
   options.initiator_info.name = fetch_initiator_type_names::kScript;

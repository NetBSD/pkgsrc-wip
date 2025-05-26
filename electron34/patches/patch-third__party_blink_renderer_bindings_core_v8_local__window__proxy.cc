$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/renderer/bindings/core/v8/local_window_proxy.cc.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/renderer/bindings/core/v8/local_window_proxy.cc
@@ -217,6 +217,7 @@ void LocalWindowProxy::Initialize() {
   }
 
   InstallConditionalFeatures();
+  GetFrame()->Client()->DidInstallConditionalFeatures(context, world_->GetWorldId());
 
   if (World().IsMainWorld()) {
     probe::DidCreateMainWorldContext(GetFrame());

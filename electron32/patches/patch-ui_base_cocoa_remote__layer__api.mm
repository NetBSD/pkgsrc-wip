$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- ui/base/cocoa/remote_layer_api.mm.orig	2024-10-18 12:35:12.352418700 +0000
+++ ui/base/cocoa/remote_layer_api.mm
@@ -10,6 +10,7 @@
 
 namespace ui {
 
+#if !IS_MAS_BUILD()
 namespace {
 // Control use of cross-process CALayers to display content directly from the
 // GPU process on Mac.
@@ -17,8 +18,10 @@ BASE_FEATURE(kRemoteCoreAnimationAPI,
              "RemoteCoreAnimationAPI",
              base::FEATURE_ENABLED_BY_DEFAULT);
 }  // namespace
+#endif
 
 bool RemoteLayerAPISupported() {
+#if !IS_MAS_BUILD()
   if (!base::FeatureList::IsEnabled(kRemoteCoreAnimationAPI))
     return false;
 
@@ -55,6 +58,9 @@ bool RemoteLayerAPISupported() {
 
   // If everything is there, we should be able to use the API.
   return true;
+#else
+  return false;
+#endif  // MAS_BUILD
 }
 
 }  // namespace

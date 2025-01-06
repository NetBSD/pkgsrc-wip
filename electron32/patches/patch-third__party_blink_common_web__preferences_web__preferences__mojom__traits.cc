$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/common/web_preferences/web_preferences_mojom_traits.cc.orig	2024-10-18 12:34:32.973309300 +0000
+++ third_party/blink/common/web_preferences/web_preferences_mojom_traits.cc
@@ -147,6 +147,19 @@ bool StructTraits<blink::mojom::WebPrefe
   out->v8_cache_options = data.v8_cache_options();
   out->record_whole_document = data.record_whole_document();
   out->stylus_handwriting_enabled = data.stylus_handwriting_enabled();
+  // Begin Electron-specific WebPreferences.
+  out->context_isolation = data.context_isolation();
+  out->is_webview = data.is_webview();
+  out->hidden_page = data.hidden_page();
+  out->offscreen = data.offscreen();
+  out->node_integration = data.node_integration();
+  out->node_integration_in_worker = data.node_integration_in_worker();
+  out->node_integration_in_sub_frames = data.node_integration_in_sub_frames();
+  out->enable_spellcheck = data.enable_spellcheck();
+  out->enable_plugins = data.enable_plugins();
+  out->enable_websql = data.enable_websql();
+  out->webview_tag = data.webview_tag();
+  // End Electron-specific WebPreferences.
   out->cookie_enabled = data.cookie_enabled();
   out->accelerated_video_decode_enabled =
       data.accelerated_video_decode_enabled();

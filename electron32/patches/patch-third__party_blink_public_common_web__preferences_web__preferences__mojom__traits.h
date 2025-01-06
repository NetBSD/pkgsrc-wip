$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/common/web_preferences/web_preferences_mojom_traits.h.orig	2024-10-18 12:34:34.624543700 +0000
+++ third_party/blink/public/common/web_preferences/web_preferences_mojom_traits.h
@@ -6,6 +6,7 @@
 #define THIRD_PARTY_BLINK_PUBLIC_COMMON_WEB_PREFERENCES_WEB_PREFERENCES_MOJOM_TRAITS_H_
 
 #include "build/build_config.h"
+#include "mojo/public/cpp/base/file_path_mojom_traits.h"
 #include "mojo/public/cpp/bindings/struct_traits.h"
 #include "net/nqe/effective_connection_type.h"
 #include "third_party/blink/public/common/common_export.h"
@@ -434,6 +435,52 @@ struct BLINK_COMMON_EXPORT StructTraits<
     return r.stylus_handwriting_enabled;
   }
 
+  // Begin Electron-specific WebPreferences.
+  static bool context_isolation(const blink::web_pref::WebPreferences& r) {
+    return r.context_isolation;
+  }
+
+  static int is_webview(const blink::web_pref::WebPreferences& r) {
+    return r.is_webview;
+  }
+
+  static bool hidden_page(const blink::web_pref::WebPreferences& r) {
+    return r.hidden_page;
+  }
+
+  static bool offscreen(const blink::web_pref::WebPreferences& r) {
+    return r.offscreen;
+  }
+
+  static bool node_integration(const blink::web_pref::WebPreferences& r) {
+    return r.node_integration;
+  }
+
+  static bool node_integration_in_worker(const blink::web_pref::WebPreferences& r) {
+    return r.node_integration_in_worker;
+  }
+
+  static bool node_integration_in_sub_frames(const blink::web_pref::WebPreferences& r) {
+    return r.node_integration_in_sub_frames;
+  }
+
+  static bool enable_spellcheck(const blink::web_pref::WebPreferences& r) {
+    return r.enable_spellcheck;
+  }
+
+  static bool enable_plugins(const blink::web_pref::WebPreferences& r) {
+    return r.enable_plugins;
+  }
+
+  static bool enable_websql(const blink::web_pref::WebPreferences& r) {
+    return r.enable_websql;
+  }
+
+  static bool webview_tag(const blink::web_pref::WebPreferences& r) {
+    return r.webview_tag;
+  }
+  // End Electron-specific WebPreferences.
+
   static bool cookie_enabled(const blink::web_pref::WebPreferences& r) {
     return r.cookie_enabled;
   }

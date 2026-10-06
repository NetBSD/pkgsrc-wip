$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/common/web_preferences/web_preferences.h.orig	2025-02-24 19:59:26.000000000 +0000
+++ third_party/blink/public/common/web_preferences/web_preferences.h
@@ -9,6 +9,7 @@
 #include <string>
 #include <vector>
 
+#include "base/files/file_path.h"
 #include "build/build_config.h"
 #include "net/nqe/effective_connection_type.h"
 #include "third_party/blink/public/common/common_export.h"
@@ -442,6 +443,20 @@ struct BLINK_COMMON_EXPORT WebPreference
   // when feature DynamicSafeAreaInsets is enabled.
   bool dynamic_safe_area_insets_enabled = false;
 
+  // Begin Electron-specific WebPreferences.
+  bool context_isolation = false;
+  bool is_webview = false;
+  bool hidden_page = false;
+  bool offscreen = false;
+  bool node_integration = false;
+  bool node_integration_in_worker = false;
+  bool node_integration_in_sub_frames = false;
+  bool enable_spellcheck = false;
+  bool enable_plugins = false;
+  bool enable_websql = false;
+  bool webview_tag = false;
+  // End Electron-specific WebPreferences.
+
   // We try to keep the default values the same as the default values in
   // chrome, except for the cases where it would require lots of extra work for
   // the embedder to use the same default value.

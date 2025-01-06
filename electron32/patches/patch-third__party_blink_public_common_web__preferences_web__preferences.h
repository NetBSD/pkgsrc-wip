$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/blink/public/common/web_preferences/web_preferences.h.orig	2024-10-18 12:34:34.624543700 +0000
+++ third_party/blink/public/common/web_preferences/web_preferences.h
@@ -10,6 +10,7 @@
 #include <vector>
 
 #include "build/build_config.h"
+#include "base/files/file_path.h"
 #include "net/nqe/effective_connection_type.h"
 #include "third_party/blink/public/common/common_export.h"
 #include "third_party/blink/public/mojom/css/preferred_color_scheme.mojom-shared.h"
@@ -441,6 +442,20 @@ struct BLINK_COMMON_EXPORT WebPreference
   // blocking user's access to the background web content.
   bool modal_context_menu = true;
 
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

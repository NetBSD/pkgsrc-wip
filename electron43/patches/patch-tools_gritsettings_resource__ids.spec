$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- tools/gritsettings/resource_ids.spec.orig	2025-02-24 19:59:26.000000000 +0000
+++ tools/gritsettings/resource_ids.spec
@@ -1385,6 +1385,11 @@
   "<(SHARED_INTERMEDIATE_DIR)/third_party/blink/public/strings/permission_element_generated_strings.grd": {
     "META": {"sizes": {"messages": [2000],}},
     "messages": [10080],
+  },
+
+  "electron/electron_resources.grd": {
+    "messages": [31750],
+    "includes": [31950],
   }
 
   # END "everything else" section.

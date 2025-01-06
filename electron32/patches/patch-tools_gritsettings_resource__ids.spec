$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- tools/gritsettings/resource_ids.spec.orig	2024-10-18 12:35:10.952978100 +0000
+++ tools/gritsettings/resource_ids.spec
@@ -1342,6 +1342,11 @@
     "includes": [8460],
   },
 
+  "electron/electron_resources.grd": {
+    "messages": [31750],
+    "includes": [31950],
+  },
+
   # END "everything else" section.
   # Everything but chrome/, components/, content/, and ios/
 

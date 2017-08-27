$NetBSD$

From: Scott Jaderholm <jaderholm@gmail.com>
Date: Sun, 16 Jul 2017 22:58:36 +0000 (-0700)
Subject: history.js: Fix clear-history for FF >= 45
X-Git-Url: http://repo.or.cz/conkeror.git/commitdiff_plain/796aa322418197b3c0df4b748f54fb0c2d3726cc

history.js: Fix clear-history for FF >= 45

Method removeAllPages was replaced by clear.
---

diff --git a/modules/history.js b/modules/history.js
index e7d2dac..dd4960a 100644
--- modules/history.js
+++ modules/history.js
@@ -110,7 +110,12 @@ interactive("clear-form-history",
 
 function clear_history () {
     var PlacesUtils = Cu.import("resource://gre/modules/PlacesUtils.jsm").PlacesUtils;
-    PlacesUtils.history.removeAllPages();
+    var xulrunner_version = get_mozilla_version();
+    if (version_compare(xulrunner_version, "45.0") < 0) {
+        PlacesUtils.history.removeAllPages();
+    } else {
+        PlacesUtils.history.clear();
+    }
 }
 interactive("clear-history",
     "Permanently delete all location history.",

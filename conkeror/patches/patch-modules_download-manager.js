$NetBSD$

From ec37576ae232914d64ba7601bf3f88f2127a293c Mon Sep 17 00:00:00 2001
From: Dimitris Papavasiliou
Date: Fri, 9 Jan 2015 16:10:25 +0200
Subject: [PATCH] modules/download-manager.js: Fix bug preventing completion of
 downloads.

---
 modules/download-manager.js | 28 ++++++++++++++--------------
 1 file changed, 14 insertions(+), 14 deletions(-)

diff --git a/modules/download-manager.js b/modules/download-manager.js
index ecd032b..f66d736 100644
--- modules/download-manager.js
+++ modules/download-manager.js
@@ -1052,24 +1052,24 @@ function download_completer (completions) {
         };
     }
     all_word_completer.call(this, forward_keywords(arguments),
-                            $completions = completions);
+                            $completions = completions,
+                            $get_string = function (x) {
+                                if (use_downloads_jsm)
+                                    return x.target.path;
+                                else
+                                    return x.displayName;
+                            },
+                            $get_description = function (x) {
+                                if (use_downloads_jsm)
+                                    return x.source.url;
+                                else
+                                    return x.source.spec
+                            });
 }
 download_completer.prototype = {
     constructor: download_completer,
     __proto__: all_word_completer.prototype,
-    toString: function () "#<download_completer>",
-    get_string: function (x) {
-        if (use_downloads_jsm)
-            return x.target.path;
-        else
-            return x.displayName;
-    },
-    get_description: function (x) {
-        if (use_downloads_jsm)
-            return x.source.url;
-        else
-            return x.source.spec
-    }
+    toString: function () "#<download_completer>"
 };
 
 minibuffer.prototype.read_download = function () {
-- 
2.7.4.GIT


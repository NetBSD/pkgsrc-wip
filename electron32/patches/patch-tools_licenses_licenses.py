$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- tools/licenses/licenses.py.orig	2024-10-18 12:35:10.960975000 +0000
+++ tools/licenses/licenses.py
@@ -335,6 +335,31 @@ SPECIAL_CASES = {
         "License": "Apache 2.0",
         "License File": ["//third_party/dawn/third_party/khronos/LICENSE"],
     },
+    os.path.join('third_party', 'electron_node'): {
+        "Name": "Node.js",
+        "URL": "https://github.com/nodejs/node",
+        "License": "MIT",
+        "License File": ["/third_party/electron_node/LICENSE"],
+    },
+    os.path.join('third_party', 'squirrel.mac'): {
+        "Name": "Squirrel",
+        "URL": "https://github.com/Squirrel/Squirrel.Mac",
+        "License": "MIT",
+        "License File": ["/third_party/squirrel.mac/LICENSE"],
+    },
+    os.path.join('third_party', 'squirrel.mac', 'vendor', 'mantle'): {
+        "Name": "Mantle",
+        "URL": "https://github.com/Mantle/Mantle",
+        "License": "MIT",
+        "License File": "/third_party/squirrel.mac/vendor/mantle/LICENSE.md",
+    },
+    os.path.join('third_party', 'squirrel.mac', 'vendor', 'ReactiveObjC'): {
+        "Name": "ReactiveObjC",
+        "URL": "https://github.com/ReactiveCocoa/ReactiveObjC",
+        "License": "MIT",
+        "License File":
+        ["/third_party/squirrel.mac/vendor/ReactiveObjC/LICENSE.md"],
+    },
 }
 
 # These buildtools/third_party directories only contain

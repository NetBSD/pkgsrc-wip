$NetBSD$

Fix Finding a path...

--- tests/test_widget.py.orig	2024-06-26 12:43:51.659372579 +0000
+++ tests/test_widget.py
@@ -24,7 +24,7 @@ def enable_hmr():


 def test_version():
-    with open(here / "../packages/anywidget/package.json") as f:
+    with open(here / "../anywidget/labextension/package.json") as f:
         pkg = json.load(f)

     assert anywidget.__version__ == pkg["version"]

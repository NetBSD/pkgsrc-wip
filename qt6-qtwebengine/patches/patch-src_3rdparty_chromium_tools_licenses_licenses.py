$NetBSD$

--- src/3rdparty/chromium/tools/licenses/licenses.py.orig	2024-11-21 04:36:37.000000000 +0000
+++ src/3rdparty/chromium/tools/licenses/licenses.py
@@ -816,6 +816,12 @@ def _GnBinary():
   exe = 'gn'
   if sys.platform.startswith('linux'):
     subdir = 'linux64'
+  elif sys.platform.startswith('freebsd'):
+    subdir = 'linux64'
+  elif sys.platform.startswith('netbsd'):
+    subdir = 'linux64'
+  elif sys.platform.startswith('openbsd'):
+    subdir = 'linux64'
   elif sys.platform == 'darwin':
     subdir = 'mac'
   elif sys.platform == 'win32':

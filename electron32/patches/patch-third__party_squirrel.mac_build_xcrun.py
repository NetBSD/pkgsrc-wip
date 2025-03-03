$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- third_party/squirrel.mac/build/xcrun.py.orig	2025-03-03 17:47:27.777594618 +0000
+++ third_party/squirrel.mac/build/xcrun.py
@@ -0,0 +1,14 @@
+#!@PYTHONBIN@
+from __future__ import print_function
+import os
+import subprocess
+import sys
+
+SOURCE_ROOT = os.path.dirname(os.path.dirname(__file__))
+cmd = "xcrun"
+args = [cmd] + sys.argv[1:]
+try:
+    subprocess.check_output(args, stderr=subprocess.STDOUT)
+except subprocess.CalledProcessError as e:
+    print("xcrun script '" + ' '.join(sys.argv[1:]) + "' failed with code '" + str(e.returncode) + "':\n" + e.output)
+    sys.exit(e.returncode)

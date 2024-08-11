$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/tools/run-paxctl.py.orig	2024-08-01 14:09:02.160198653 +0000
+++ v8/tools/run-paxctl.py
@@ -0,0 +1,16 @@
+#!@PYTHONBIN@
+# Copyright 2014 the V8 project authors. All rights reserved.
+# Use of this source code is governed by a BSD-style license that can be
+# found in the LICENSE file.
+
+"""This program wraps an arbitrary command since gn currently can only execute
+scripts."""
+
+import subprocess
+import sys
+import os
+
+with open(sys.argv[1], 'w'):
+  os.utime(sys.argv[1], None)
+
+sys.exit(subprocess.call(sys.argv[2:]))

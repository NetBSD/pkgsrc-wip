$NetBSD$

--- /dev/null	2021-03-15 07:21:43.376276699 +0000
+++ src/3rdparty/chromium/v8/tools/run-paxctl.py
@@ -0,0 +1,16 @@
+#!/usr/bin/env python
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

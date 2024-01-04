$NetBSD$

# Add BSD support, eliminate subprocess on Darwin

--- joblib/externals/loky/backend/context.py.orig	2023-06-29 15:14:21.000000000 +0000
+++ joblib/externals/loky/backend/context.py
@@ -11,6 +11,7 @@
 #
 import os
 import sys
+import sysctl
 import math
 import subprocess
 import traceback
@@ -267,13 +268,14 @@ def _count_physical_cores():
             ]
             cpu_count_physical = sum(map(int, cpu_info))
         elif sys.platform == "darwin":
-            cpu_info = subprocess.run(
-                "sysctl -n hw.physicalcpu".split(),
-                capture_output=True,
-                text=True,
-            )
-            cpu_info = cpu_info.stdout
-            cpu_count_physical = int(cpu_info)
+            cpu_count_physical = int(sysctl.filter("hw.physicalcpu")[0].value);
+        elif sys.platform.startswith('freebsd'):
+            cpu_count_physical = int(sysctl.filter("kern.smp.cores")[0].value);
+        elif sys.platform.startswith('netbsd'):
+            # FIXME: This reports the number of hyperthreads
+            # We want independent cores to prevent oversubscription
+            cpu_count_physical = int(sysctl.filter("hw.ncpu")[0].value);
+        # FIXME: Add OpenBSD, Dragonfly (probably the same as FreeBSD)
         else:
             raise NotImplementedError(f"unsupported platform: {sys.platform}")
 

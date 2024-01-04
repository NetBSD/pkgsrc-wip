$NetBSD$

# Add BSD support

--- joblib/externals/loky/backend/context.py.orig	2023-06-29 15:14:21.000000000 +0000
+++ joblib/externals/loky/backend/context.py
@@ -245,6 +245,8 @@ def _count_physical_cores():
         return physical_cores_cache, exception
 
     # Not cached yet, find it
+    # Using subprocesses is inefficient, but python has no portable
+    # sysctl interface at this time
     try:
         if sys.platform == "linux":
             cpu_info = subprocess.run(
@@ -274,6 +276,25 @@ def _count_physical_cores():
             )
             cpu_info = cpu_info.stdout
             cpu_count_physical = int(cpu_info)
+        elif sys.platform.startswith('freebsd'):
+            cpu_info = subprocess.run(
+                "sysctl -n kern.smp.cores".split(),
+                capture_output=True,
+                text=True,
+            )
+            cpu_info = cpu_info.stdout
+            cpu_count_physical = int(cpu_info)
+        elif sys.platform.startswith('netbsd'):
+            # FIXME: This reports the number of hyperthreads
+            # We want independent cores to prevent oversubscription
+        # FIXME: Add OpenBSD, Dragonfly (probably the same as FreeBSD)
+            cpu_info = subprocess.run(
+                "sysctl -n hw.ncpu".split(),
+                capture_output=True,
+                text=True,
+            )
+            cpu_info = cpu_info.stdout
+            cpu_count_physical = int(cpu_info)
         else:
             raise NotImplementedError(f"unsupported platform: {sys.platform}")
 

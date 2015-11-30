$NetBSD$

--- lldb/packages/Python/lldbsuite/test/lldbtest.py.orig	2015-11-20 22:43:05.000000000 +0000
+++ lldb/packages/Python/lldbsuite/test/lldbtest.py
@@ -430,6 +430,8 @@ def getsource_if_available(obj):
 def builder_module():
     if sys.platform.startswith("freebsd"):
         return __import__("builder_freebsd")
+    if sys.platform.startswith("netbsd"):
+        return __import__("builder_netbsd")
     return __import__("builder_" + sys.platform)
 
 def run_adb_command(cmd, device_id):

$NetBSD$

--- lldb/packages/Python/lldbsuite/test/plugins/builder_netbsd.py.orig	2015-11-30 03:53:10.000000000 +0000
+++ lldb/packages/Python/lldbsuite/test/plugins/builder_netbsd.py
@@ -0,0 +1,4 @@
+from builder_base import *
+
+def buildDsym(sender=None, architecture=None, compiler=None, dictionary=None, clean=True):
+    return False

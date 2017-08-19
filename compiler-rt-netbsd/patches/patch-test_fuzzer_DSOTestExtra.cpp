$NetBSD$

--- test/fuzzer/DSOTestExtra.cpp.orig	2017-08-19 18:02:19.283973480 +0000
+++ test/fuzzer/DSOTestExtra.cpp
@@ -0,0 +1,11 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Source code for a simple DSO.
+
+int DSOTestExtra(int a) {
+  if (a < 452345)
+    return 0;
+  return 1;
+}
+

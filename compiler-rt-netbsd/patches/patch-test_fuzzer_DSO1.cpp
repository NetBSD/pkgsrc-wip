$NetBSD$

--- test/fuzzer/DSO1.cpp.orig	2017-08-19 18:02:19.283784592 +0000
+++ test/fuzzer/DSO1.cpp
@@ -0,0 +1,14 @@
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+
+// Source code for a simple DSO.
+#ifdef _WIN32
+__declspec( dllexport )
+#endif
+int DSO1(int a) {
+  if (a < 123456)
+    return 0;
+  return 1;
+}
+
+void Uncovered1() { }

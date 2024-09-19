$NetBSD$

--- src/VBox/Additions/common/crOpenGL/NetBSD_exports.py.orig	2016-07-06 19:36:20.413032855 +0000
+++ src/VBox/Additions/common/crOpenGL/NetBSD_exports.py
@@ -0,0 +1,11 @@
+# Copyright (c) 2001, Stanford University
+# All rights reserved.
+#
+# See the file LICENSE.txt for information on redistributing this software.
+
+import entrypoints
+
+hacks = []
+
+entrypoints.GenerateEntrypoints(hacks)
+

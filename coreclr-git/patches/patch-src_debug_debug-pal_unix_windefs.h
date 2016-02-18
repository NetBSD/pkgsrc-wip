$NetBSD$

--- src/debug/debug-pal/unix/windefs.h.orig	2016-02-18 22:12:18.171417621 +0000
+++ src/debug/debug-pal/unix/windefs.h
@@ -0,0 +1,12 @@
+// Licensed to the .NET Foundation under one or more agreements.
+// The .NET Foundation licenses this file to you under the MIT license.
+// See the LICENSE file in the project root for more information.
+
+// It'd be nice to be able to include some existing header from the main PAL, 
+// but they tend to pull too much stuff that breaks everything.
+
+#include <cstddef>
+#include <assert.h>
+#define _ASSERTE assert
+
+typedef unsigned int DWORD;

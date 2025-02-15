$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- v8/test/mjsunit/regress/regress-374627491.js.orig	2025-02-15 09:43:46.595561627 +0000
+++ v8/test/mjsunit/regress/regress-374627491.js
@@ -0,0 +1,26 @@
+// Copyright 2024 the V8 project authors. All rights reserved.
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+class B { }
+class C extends B {
+  constructor() {
+    let x = 0;
+    switch (0) {
+      case 0:
+      case 1:
+      case 2:
+      case 3:
+      case 4:
+      case 5:
+      case 6:
+      case 7:
+      case 8:
+      case 9:
+        x += this;
+        break;
+      case this:
+    }
+  }
+}
+assertThrows(() => { new C(); }, ReferenceError);

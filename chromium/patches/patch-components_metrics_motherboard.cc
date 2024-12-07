$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/metrics/motherboard.cc.orig	2024-12-03 23:30:15.985409700 +0000
+++ components/metrics/motherboard.cc
@@ -1,6 +1,7 @@
 // Copyright 2022 The Chromium Authors
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+// CHECK
 
 #include "components/metrics/motherboard.h"
 

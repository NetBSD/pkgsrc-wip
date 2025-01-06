$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- components/metrics/motherboard.cc.orig	2024-10-18 12:34:06.878351400 +0000
+++ components/metrics/motherboard.cc
@@ -1,6 +1,7 @@
 // Copyright 2022 The Chromium Authors
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+// CHECK
 
 #include "components/metrics/motherboard.h"
 

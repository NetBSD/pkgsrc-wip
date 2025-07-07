$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/zygote/zygote_linux.cc.orig	2025-06-30 06:54:11.000000000 +0000
+++ content/zygote/zygote_linux.cc
@@ -1,6 +1,7 @@
 // Copyright 2012 The Chromium Authors
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #include "content/zygote/zygote_linux.h"
 
@@ -705,3 +706,4 @@ void Zygote::HandleReinitializeLoggingRe
 }
 
 }  // namespace content
+#endif

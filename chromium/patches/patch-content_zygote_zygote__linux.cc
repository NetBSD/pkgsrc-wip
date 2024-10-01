$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/zygote/zygote_linux.cc.orig	2024-09-24 20:49:29.142919800 +0000
+++ content/zygote/zygote_linux.cc
@@ -1,6 +1,7 @@
 // Copyright 2012 The Chromium Authors
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #ifdef UNSAFE_BUFFERS_BUILD
 // TODO(crbug.com/342213636): Remove this and spanify to fix the errors.
@@ -723,3 +724,4 @@ void Zygote::HandleReinitializeLoggingRe
 }
 
 }  // namespace content
+#endif

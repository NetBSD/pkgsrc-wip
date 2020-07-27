$NetBSD$

--- sandbox/linux/services/init_process_reaper.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ sandbox/linux/services/init_process_reaper.cc
@@ -1,6 +1,7 @@
 // Copyright 2013 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if defined(OS_LINUX)
 
 #include "sandbox/linux/services/init_process_reaper.h"
 
@@ -100,3 +101,4 @@ bool CreateInitProcessReaper(base::OnceC
 }
 
 }  // namespace sandbox.
+#endif

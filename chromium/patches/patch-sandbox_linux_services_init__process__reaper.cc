$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- sandbox/linux/services/init_process_reaper.cc.orig	2024-07-24 02:44:43.549450900 +0000
+++ sandbox/linux/services/init_process_reaper.cc
@@ -2,6 +2,7 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#if 0
 #include "sandbox/linux/services/init_process_reaper.h"
 
 #include <signal.h>
@@ -100,3 +101,4 @@ bool CreateInitProcessReaper(base::OnceC
 }
 
 }  // namespace sandbox.
+#endif

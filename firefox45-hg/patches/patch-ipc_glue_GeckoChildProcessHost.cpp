$NetBSD: patch-ipc_glue_GeckoChildProcessHost.cpp,v 1.3 2015/01/29 11:43:22 thomasklausner Exp $

--- ipc/glue/GeckoChildProcessHost.cpp.orig	2014-09-28 08:30:05.000000000 +0000
+++ ipc/glue/GeckoChildProcessHost.cpp
@@ -4,7 +4,13 @@
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
+#if defined(__NetBSD__)
+_Pragma("GCC visibility push(default)")
+#endif
 #include "GeckoChildProcessHost.h"
+#if defined(__NetBSD__)
+_Pragma("GCC visibility pop")
+#endif
 
 #include "base/command_line.h"
 #include "base/string_util.h"

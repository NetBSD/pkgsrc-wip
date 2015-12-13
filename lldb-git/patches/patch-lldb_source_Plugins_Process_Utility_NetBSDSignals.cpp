$NetBSD$

--- lldb/source/Plugins/Process/Utility/NetBSDSignals.cpp.orig	2015-12-13 05:13:01.000000000 +0000
+++ lldb/source/Plugins/Process/Utility/NetBSDSignals.cpp
@@ -0,0 +1,34 @@
+//===-- NetBSDSignals.cpp --------------------------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+// C Includes
+// C++ Includes
+// Other libraries and framework includes
+// Project includes
+#include "NetBSDSignals.h"
+
+using namespace lldb_private;
+
+NetBSDSignals::NetBSDSignals()
+    : UnixSignals()
+{
+    Reset();
+}
+
+void
+NetBSDSignals::Reset()
+{
+    UnixSignals::Reset();
+    //        SIGNO  NAME          SUPPRESS STOP   NOTIFY DESCRIPTION
+    //        ====== ============  ======== ====== ====== ===================================================
+    AddSignal (32,   "SIGPWR",     false,   true , true , "power fail/restart (not reset when caught)");
+#ifdef SIGRTMIN /* SIGRTMAX */
+    /* Kernel only; not exposed to userland yet */
+#endif
+}

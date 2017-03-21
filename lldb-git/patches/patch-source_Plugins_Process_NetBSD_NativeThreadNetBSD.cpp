$NetBSD$

--- source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp.orig	2017-03-21 14:39:27.452920481 +0000
+++ source/Plugins/Process/NetBSD/NativeThreadNetBSD.cpp
@@ -0,0 +1,21 @@
+//===-- NativeThreadNetBSD.cpp -------------------------------- -*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#include "NativeThreadNetBSD.h"
+#include "NativeRegisterContextNetBSD.h"
+
+#include "NativeProcessNetBSD.h"
+
+using namespace lldb;
+using namespace lldb_private;
+using namespace lldb_private::process_netbsd;
+
+NativeThreadNetBSD::NativeThreadNetBSD(NativeProcessNetBSD *process,
+                                       lldb::tid_t tid)
+    : NativeThreadProtocol(process, tid) {}

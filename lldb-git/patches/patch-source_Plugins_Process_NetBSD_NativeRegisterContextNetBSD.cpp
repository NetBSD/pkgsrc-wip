$NetBSD$

--- source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.cpp.orig	2017-03-21 14:39:27.380399180 +0000
+++ source/Plugins/Process/NetBSD/NativeRegisterContextNetBSD.cpp
@@ -0,0 +1,19 @@
+//===-- NativeRegisterContextNetBSD.cpp -------------------------*- C++ -*-===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+
+#include "NativeRegisterContextNetBSD.h"
+
+using namespace lldb_private;
+using namespace lldb_private::process_netbsd;
+
+NativeRegisterContextNetBSD::NativeRegisterContextNetBSD(
+    NativeThreadProtocol &native_thread, uint32_t concrete_frame_idx,
+    RegisterInfoInterface *reg_info_interface_p)
+    : NativeRegisterContextRegisterInfo(native_thread, concrete_frame_idx,
+                                        reg_info_interface_p) {}

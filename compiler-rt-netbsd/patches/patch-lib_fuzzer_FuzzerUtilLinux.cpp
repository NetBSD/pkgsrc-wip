$NetBSD$

--- lib/fuzzer/FuzzerUtilLinux.cpp.orig	2017-08-19 18:06:22.041673476 +0000
+++ lib/fuzzer/FuzzerUtilLinux.cpp
@@ -0,0 +1,24 @@
+//===- FuzzerUtilLinux.cpp - Misc utils for Linux. ------------------------===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+// Misc utils for Linux.
+//===----------------------------------------------------------------------===//
+#include "FuzzerDefs.h"
+#if LIBFUZZER_LINUX || LIBFUZZER_NETBSD
+
+#include <stdlib.h>
+
+namespace fuzzer {
+
+int ExecuteCommand(const std::string &Command) {
+  return system(Command.c_str());
+}
+
+} // namespace fuzzer
+
+#endif // LIBFUZZER_LINUX || LIBFUZZER_NETBSD

$NetBSD$

--- lib/fuzzer/FuzzerSHA1.h.orig	2017-08-19 18:02:19.279456327 +0000
+++ lib/fuzzer/FuzzerSHA1.h
@@ -0,0 +1,33 @@
+//===- FuzzerSHA1.h - Internal header for the SHA1 utils --------*- C++ -* ===//
+//
+//                     The LLVM Compiler Infrastructure
+//
+// This file is distributed under the University of Illinois Open Source
+// License. See LICENSE.TXT for details.
+//
+//===----------------------------------------------------------------------===//
+// SHA1 utils.
+//===----------------------------------------------------------------------===//
+
+#ifndef LLVM_FUZZER_SHA1_H
+#define LLVM_FUZZER_SHA1_H
+
+#include "FuzzerDefs.h"
+#include <cstddef>
+#include <stdint.h>
+
+namespace fuzzer {
+
+// Private copy of SHA1 implementation.
+static const int kSHA1NumBytes = 20;
+
+// Computes SHA1 hash of 'Len' bytes in 'Data', writes kSHA1NumBytes to 'Out'.
+void ComputeSHA1(const uint8_t *Data, size_t Len, uint8_t *Out);
+
+std::string Sha1ToString(const uint8_t Sha1[kSHA1NumBytes]);
+
+std::string Hash(const Unit &U);
+
+}  // namespace fuzzer
+
+#endif  // LLVM_FUZZER_SHA1_H

$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- build/rust/allocator/alias.cc.orig	2025-07-08 14:12:31.098995941 +0000
+++ build/rust/allocator/alias.cc
@@ -0,0 +1,22 @@
+// Copyright 2023 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+// This file has been copied from //base/debug/alias.cc ( additionally the APIs
+// were moved into the `build_rust_std` namespace).
+//
+// TODO(crbug.com/40279749): Avoid code duplication / reuse code.
+
+#include "build/rust/allocator/alias.h"
+
+#include "build/rust/allocator/compiler_specific.h"
+
+namespace build_rust_std {
+namespace debug {
+
+// This file/function should be excluded from LTO/LTCG to ensure that the
+// compiler can't see this function's implementation when compiling calls to it.
+NOINLINE void Alias(const void* var) {}
+
+}  // namespace debug
+}  // namespace build_rust_std

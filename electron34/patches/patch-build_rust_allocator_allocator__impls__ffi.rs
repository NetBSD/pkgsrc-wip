$NetBSD$

* Part of patchset to build electron on NetBSD
* Based on OpenBSD's chromium patches, and
  FreeBSD's electron patches

--- build/rust/allocator/allocator_impls_ffi.rs.orig	2025-07-08 14:12:31.099724860 +0000
+++ build/rust/allocator/allocator_impls_ffi.rs
@@ -0,0 +1,19 @@
+// Copyright 2025 The Chromium Authors
+// Use of this source code is governed by a BSD-style license that can be
+// found in the LICENSE file.
+
+//! FFI for `allocator_impls.h` is in a separate `.rs` file/module to
+//! better support conditional compilation (these functions are only
+//! used under `#[cfg(rust_allocator_uses_allocator_impls_h)]`.
+
+#[cxx::bridge(namespace = "rust_allocator_internal")]
+pub mod ffi {
+    extern "C++" {
+        include!("build/rust/allocator/allocator_impls.h");
+
+        unsafe fn alloc(size: usize, align: usize) -> *mut u8;
+        unsafe fn dealloc(p: *mut u8, size: usize, align: usize);
+        unsafe fn realloc(p: *mut u8, old_size: usize, align: usize, new_size: usize) -> *mut u8;
+        unsafe fn alloc_zeroed(size: usize, align: usize) -> *mut u8;
+    }
+}

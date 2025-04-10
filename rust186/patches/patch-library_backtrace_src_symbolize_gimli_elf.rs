$NetBSD: patch-library_backtrace_src_symbolize_gimli_elf.rs,v 1.8 2024/04/18 09:29:42 pin Exp $

Make NetBSD also find its debug libraries, if present.

--- library/backtrace/src/symbolize/gimli/elf.rs.orig	2022-04-04 09:41:26.000000000 +0000
+++ library/backtrace/src/symbolize/gimli/elf.rs
@@ -395,11 +395,18 @@ fn decompress_zstd(mut input: &[u8], mut
     Some(())
 }
 
+#[cfg(target_os = "netbsd")]
+const DEBUG_PATH: &str = "/usr/libdata/debug";
+#[cfg(not(target_os = "netbsd"))]
 const DEBUG_PATH: &str = "/usr/lib/debug";
 
 fn debug_path_exists() -> bool {
     cfg_if::cfg_if! {
-        if #[cfg(any(target_os = "freebsd", target_os = "hurd", target_os = "linux"))] {
+        if #[cfg(any(target_os = "freebsd",
+		     target_os = "netbsd",
+                     target_os = "hurd",
+		     target_os = "linux"
+        ))] {
             use core::sync::atomic::{AtomicU8, Ordering};
             static DEBUG_PATH_EXISTS: AtomicU8 = AtomicU8::new(0);
 

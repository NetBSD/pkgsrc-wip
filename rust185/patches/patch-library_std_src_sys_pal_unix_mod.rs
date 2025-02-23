$NetBSD$

Add libexecinfo for backtrace() on NetBSD.

--- library/std/src/sys/pal/unix/mod.rs.orig	2024-03-22 12:47:54.470537834 +0000
+++ library/std/src/sys/pal/unix/mod.rs
@@ -384,6 +384,7 @@ cfg_if::cfg_if! {
         #[link(name = "pthread")]
         extern "C" {}
     } else if #[cfg(target_os = "netbsd")] {
+        #[link(name = "execinfo")]
         #[link(name = "pthread")]
         #[link(name = "rt")]
         extern "C" {}

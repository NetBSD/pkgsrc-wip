$NetBSD$

Minimally invasive patch to allow compilation on NetBSD.

Pull request: https://github.com/andrewchambers/bupstash/pull/400

--- src/fprefetch.rs.orig	2024-02-15 18:55:40.800407913 +0000
+++ src/fprefetch.rs
@@ -64,6 +64,8 @@ fn open_file_for_streaming(fpath: &std::
             // Perhaps F_RDADVISE ?
         } else if #[cfg(target_os = "openbsd")] {
             // XXX can we do anything here?
+        } else if #[cfg(target_os = "netbsd")] {
+            // XXX can we do anything here?
         } else {
             // We would like to use something like POSIX_FADV_NOREUSE to preserve
             // the user page cache... this is actually a NOOP on linux.

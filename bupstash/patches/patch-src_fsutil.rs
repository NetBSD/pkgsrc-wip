$NetBSD$

Minimally invasive patch to allow backup and restore of device nodes on NetBSD.

Pull request: https://github.com/andrewchambers/bupstash/pull/400

--- src/fsutil.rs.orig	2024-02-15 18:55:31.828298063 +0000
+++ src/fsutil.rs
@@ -167,6 +167,20 @@ cfg_if::cfg_if! {
             (dev & 0xff) | ((dev & 0xffff0000) >> 8)
         }
 
+    } else if #[cfg(target_os = "netbsd")] {
+
+        pub fn makedev(major: u64, minor: u64) -> libc::dev_t {
+            (((major & 0xfff) << 8) | (minor & 0xff) | ((minor & 0xfff00) << 12)) as libc::dev_t
+        }
+
+        pub fn dev_major(dev: u64) -> u64 {
+            (dev >> 8) & 0xfff
+        }
+
+        pub fn dev_minor(dev :u64) -> u64 {
+            (dev & 0xff) | ((dev & 0xfff00000) >> 12)
+        }
+
      } else if #[cfg(target_os = "freebsd")] {
 
         // See https://github.com/freebsd/freebsd-src/sys/sys/types.h

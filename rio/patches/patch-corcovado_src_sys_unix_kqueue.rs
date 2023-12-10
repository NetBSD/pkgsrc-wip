$NetBSD$

Add NetBSD support.

--- corcovado/src/sys/unix/kqueue.rs.orig	2023-12-10 20:06:10.635526974 +0000
+++ corcovado/src/sys/unix/kqueue.rs
@@ -346,6 +346,7 @@ impl Events {
             #[cfg(any(
                 target_os = "dragonfly",
                 target_os = "freebsd",
+                target_os = "netbsd",
                 target_os = "ios",
                 target_os = "macos"
             ))]
@@ -407,6 +408,7 @@ fn does_not_register_rw() {
 #[cfg(any(
     target_os = "dragonfly",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "ios",
     target_os = "macos"
 ))]

$NetBSD$

Add NetBSD support.

--- corcovado/src/sys/unix/ready.rs.orig	2023-12-10 20:09:23.686406007 +0000
+++ corcovado/src/sys/unix/ready.rs
@@ -98,6 +98,7 @@ const HUP: usize = 0b00_1000;
 #[cfg(any(
     target_os = "dragonfly",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "ios",
     target_os = "macos"
 ))]
@@ -106,6 +107,7 @@ const AIO: usize = 0b01_0000;
 #[cfg(not(any(
     target_os = "dragonfly",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "ios",
     target_os = "macos"
 )))]
@@ -176,6 +178,7 @@ impl UnixReady {
     #[cfg(any(
         target_os = "dragonfly",
         target_os = "freebsd",
+        target_os = "netbsd",
         target_os = "ios",
         target_os = "macos"
     ))]
@@ -186,6 +189,7 @@ impl UnixReady {
     #[cfg(not(any(
         target_os = "dragonfly",
         target_os = "freebsd",
+        target_os = "netbsd",
         target_os = "ios",
         target_os = "macos"
     )))]
@@ -318,6 +322,7 @@ impl UnixReady {
     #[cfg(any(
         target_os = "dragonfly",
         target_os = "freebsd",
+        target_os = "netbsd",
         target_os = "ios",
         target_os = "macos"
     ))]
@@ -330,6 +335,7 @@ impl UnixReady {
     #[cfg(not(any(
         target_os = "dragonfly",
         target_os = "freebsd",
+        target_os = "netbsd",
         target_os = "ios",
         target_os = "macos"
     )))]

$NetBSD$

Fix build on NetBSD.

--- ../vendor/nix-0.31.2/src/sys/wait.rs.orig	2026-06-10 06:47:04.530136501 +0000
+++ ../vendor/nix-0.31.2/src/sys/wait.rs
@@ -241,6 +241,7 @@ impl WaitStatus {
     #[cfg(any(
         target_os = "android",
         target_os = "freebsd",
+        target_os = "netbsd",
         target_os = "haiku",
         all(target_os = "linux", not(target_env = "uclibc")),
     ))]
@@ -326,6 +327,7 @@ pub fn wait() -> Result<WaitStatus> {
 #[cfg(any(
     target_os = "android",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "haiku",
     all(target_os = "linux", not(target_env = "uclibc")),
 ))]
@@ -354,6 +356,7 @@ pub enum Id<'fd> {
 #[cfg(any(
     target_os = "android",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "haiku",
     all(target_os = "linux", not(target_env = "uclibc")),
 ))]

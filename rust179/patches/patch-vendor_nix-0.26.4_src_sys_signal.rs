$NetBSD$

Avoid use of nonexistent SigevThreadId on NetBSD/mipsel.

--- vendor/nix-0.26.4/src/sys/signal.rs.orig	2024-08-06 07:00:59.438254328 +0000
+++ vendor/nix-0.26.4/src/sys/signal.rs
@@ -1069,7 +1069,8 @@ mod sigevent {
                 SigevNotify::SigevThreadId{..} => libc::SIGEV_THREAD_ID,
                 #[cfg(all(target_os = "linux", target_env = "uclibc"))]
                 SigevNotify::SigevThreadId{..} => libc::SIGEV_THREAD_ID,
-                #[cfg(any(all(target_os = "linux", target_env = "musl"), target_arch = "mips"))]
+                #[cfg(all(target_os = "linux", any(target_env = "musl", target_arch = "mips")))]
+
                 SigevNotify::SigevThreadId{..} => 4  // No SIGEV_THREAD_ID defined
             };
             sev.sigev_signo = match sigev_notify {

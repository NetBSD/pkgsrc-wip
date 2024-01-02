$NetBSD$

Add support for NetBSD.

--- ../vendor/boringtun-0.6.0/src/sleepyinstant/unix.rs.orig	2024-01-01 23:15:11.332028854 +0000
+++ ../vendor/boringtun-0.6.0/src/sleepyinstant/unix.rs
@@ -3,9 +3,9 @@ use std::time::Duration;
 use nix::sys::time::TimeSpec;
 use nix::time::{clock_gettime, ClockId};
 
-#[cfg(any(target_os = "macos", target_os = "ios"))]
+#[cfg(any(target_os = "macos", target_os = "ios", target_os = "netbsd"))]
 const CLOCK_ID: ClockId = ClockId::CLOCK_MONOTONIC;
-#[cfg(not(any(target_os = "macos", target_os = "ios")))]
+#[cfg(not(any(target_os = "macos", target_os = "ios", target_os = "netbsd")))]
 const CLOCK_ID: ClockId = ClockId::CLOCK_BOOTTIME;
 
 #[derive(Clone, Copy, Debug)]

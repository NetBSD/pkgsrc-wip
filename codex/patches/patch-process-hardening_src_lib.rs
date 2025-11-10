$NetBSD$

Allow define on NetBSD.

--- process-hardening/src/lib.rs.orig	2025-11-10 10:10:29.289117665 +0000
+++ process-hardening/src/lib.rs
@@ -1,3 +1,5 @@
+use libc;
+
 /// This is designed to be called pre-main() (using `#[ctor::ctor]`) to perform
 /// various process hardening steps, such as
 /// - disabling core dumps
@@ -20,7 +22,7 @@ const PRCTL_FAILED_EXIT_CODE: i32 = 5;
 #[cfg(target_os = "macos")]
 const PTRACE_DENY_ATTACH_FAILED_EXIT_CODE: i32 = 6;
 
-#[cfg(any(target_os = "linux", target_os = "android", target_os = "macos"))]
+#[cfg(any(target_os = "linux", target_os = "android", target_os = "macos", target_os = "netbsd"))]
 const SET_RLIMIT_CORE_FAILED_EXIT_CODE: i32 = 7;
 
 #[cfg(any(target_os = "linux", target_os = "android"))]

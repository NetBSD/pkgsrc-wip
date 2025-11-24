$NetBSD$

Fix build on NetBSD.
https://github.com/openai/codex/pull/7238

--- process-hardening/src/lib.rs.orig	2025-11-24 10:15:16.068328981 +0000
+++ process-hardening/src/lib.rs
@@ -29,6 +29,7 @@ const PTRACE_DENY_ATTACH_FAILED_EXIT_COD
     target_os = "android",
     target_os = "macos",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "openbsd"
 ))]
 const SET_RLIMIT_CORE_FAILED_EXIT_CODE: i32 = 7;

$NetBSD$

Gate a helper used only by the Linux parent-death-signal path, so it is not
dead code on NetBSD. The cfg keeps "test" so the existing unit test still
builds everywhere.

--- src/cli/dispatch.rs.orig
+++ src/cli/dispatch.rs
@@ -21,10 +21,10 @@ use super::{
 };
 use provider_init::ProviderChoice;
 
+#[cfg(any(test, target_os = "linux"))] // tested everywhere, used by Linux path
 fn is_file_controlled_debug_client() -> bool {
     std::env::var_os("JCODE_DEBUG_CMD_PATH").is_some()
 }
-
 #[cfg(target_os = "linux")]
 fn is_orphan_adopter_name(name: &str) -> bool {
     matches!(name.trim(), "init" | "systemd")
@@ -42,8 +42,8 @@ fn parent_is_orphan_adopter(parent_pid: libc::pid_t) -> bool {
 /// Tie file-controlled debug clients to the process that launched them.
 ///
 /// These clients are automation helpers, not user-owned terminals. Without a
-/// parent-death signal they are reparented to init when a verification script
-/// or debug server exits, retaining a full TUI and session history indefinitely.
+/// parent-death signal they are reparented to init when a verification script or
+/// debug server exits, retaining a full TUI and session history indefinitely.
 #[cfg(target_os = "linux")]
 fn arm_debug_client_parent_death_signal() {
     if !is_file_controlled_debug_client() {

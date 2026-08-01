$NetBSD$

Gate a helper used only by the Linux pidfd path to Linux, so it is not dead
code on NetBSD.

--- crates/jcode-base/src/claude_live.rs.orig
+++ crates/jcode-base/src/claude_live.rs
@@ -248,6 +248,9 @@ fn registry_still_matches(session: &LiveClaudeSession) -> bool {
     })
 }
 
+/// Only the Linux pidfd-based stop path can confirm the exact process exited,
+/// so the registry cleanup it guards is Linux-only too.
+#[cfg(target_os = "linux")]
 fn remove_registry_if_same(session: &LiveClaudeSession) {
     if registry_still_matches(session) {
         let _ = std::fs::remove_file(&session.registry_path);

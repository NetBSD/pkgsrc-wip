$NetBSD$

Gate an inotify-only constant to Linux so it is not dead code on NetBSD.

--- crates/jcode-app-core/src/server/reload_state.rs.orig
+++ crates/jcode-app-core/src/server/reload_state.rs
@@ -3,7 +3,9 @@ use serde::{Deserialize, Serialize};
 use std::path::PathBuf;
 use std::time::Duration;
 
-#[cfg(unix)]
+/// Poll interval for the inotify-based reload handoff wait, which only the
+/// Linux path uses.
+#[cfg(target_os = "linux")]
 const RELOAD_HANDOFF_EVENT_POLL_MS: i32 = 100;
 
 pub fn reload_marker_path() -> PathBuf {

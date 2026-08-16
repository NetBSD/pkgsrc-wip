$NetBSD$

Do not use the system trash when deleting from the file explorer on NetBSD.

NetBSD has no system-wide trash facility, so the trash crate cannot honour
trash::delete() there and the editor aborts instead of reporting a plain
error to the user.  On NetBSD, move the file to the editor's own trash
directory (~/.local/share/fresh/trash/) directly; on every other platform,
keep using the system trash and fall back to that directory only when
trash::delete() fails.

Not yet submitted upstream.

--- crates/fresh-editor/src/app/file_explorer.rs.orig	2026-08-11 21:11:11.000000000 +0000
+++ crates/fresh-editor/src/app/file_explorer.rs
@@ -643,6 +643,7 @@ impl Editor {
     /// Perform the actual file explorer delete operation (called after prompt confirmation)
     /// For local files: moves to system trash/recycle bin
     /// For remote files: moves to ~/.local/share/fresh/trash/ on remote
+    /// Falls back to ~/.local/share/fresh/trash/ when system trash is unavailable (e.g. NetBSD).
     pub fn perform_file_explorer_delete(&mut self, path: std::path::PathBuf, _is_dir: bool) {
         let name = path
             .file_name()
@@ -650,7 +651,7 @@ impl Editor {
             .unwrap_or_default();
 
         // For remote files, move to remote trash directory
-        // For local files, use system trash
+        // For local files, try system trash, then fall back to local trash directory
         let delete_result = if self
             .authority()
             .filesystem
@@ -659,7 +660,7 @@ impl Editor {
         {
             self.move_to_remote_trash(&path)
         } else {
-            trash::delete(&path).map_err(std::io::Error::other)
+            self.try_system_trash_or_local(&path)
         };
 
         match delete_result {
@@ -770,6 +771,29 @@ impl Editor {
 
         // Move to trash
         self.authority().filesystem.rename(path, &trash_path)
+    }
+
+    /// Try system trash, falling back to the local trash directory on failure.
+    /// On platforms where the `trash` crate is known to be unreliable (e.g. NetBSD),
+    /// skip the system trash attempt entirely.
+    #[cfg(target_os = "netbsd")]
+    fn try_system_trash_or_local(&self, path: &std::path::Path) -> std::io::Result<()> {
+        tracing::info!("NetBSD detected — skipping system trash, using local trash directory instead.");
+        self.move_to_remote_trash(path)
+    }
+
+    #[cfg(not(target_os = "netbsd"))]
+    fn try_system_trash_or_local(&self, path: &std::path::Path) -> std::io::Result<()> {
+        match trash::delete(path) {
+            Ok(()) => Ok(()),
+            Err(e) => {
+                tracing::warn!(
+                    "System trash failed for {:?}: {}. Falling back to local trash directory.",
+                    path, e
+                );
+                self.move_to_remote_trash(path)
+            }
+        }
     }
 
     pub fn file_explorer_rename(&mut self) {

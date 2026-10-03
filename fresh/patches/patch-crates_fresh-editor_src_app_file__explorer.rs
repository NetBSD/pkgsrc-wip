$NetBSD$

Do not use the system trash when deleting from the file explorer on NetBSD.

NetBSD has no system-wide trash facility, so the trash crate cannot honour
trash::delete() there and the editor aborts instead of reporting a plain
error to the user.  On NetBSD, move the file to the editor's own trash
directory (~/.local/share/fresh/trash/) directly; on every other platform,
keep using the system trash and fall back to that directory only when
trash::delete() fails.

Not yet submitted upstream.

--- crates/fresh-editor/src/app/file_explorer.rs.orig
+++ crates/fresh-editor/src/app/file_explorer.rs
@@ -812,7 +812,30 @@
         {
             self.move_to_remote_trash(path)
         } else {
-            trash::delete(path).map_err(std::io::Error::other)
+            self.try_system_trash_or_local(path)
+        }
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
         }
     }
 

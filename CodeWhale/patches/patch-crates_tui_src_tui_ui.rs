$NetBSD$

Define open_external_url() on NetBSD too.  It merely forwards to
crate::utils::open_url(), which is implemented for every platform
(returning a graceful "unsupported" error on non mac/linux/windows
targets), but this cfg gate omitted NetBSD while the call site is
unconditional, so the build failed with E0425 (function not found).

--- crates/tui/src/tui/ui.rs.orig
+++ crates/tui/src/tui/ui.rs
@@ -5925,7 +5925,7 @@ use std::process::{Command, Stdio};
 #[cfg(test)]
 use std::process::{Command, Stdio};
 
-#[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows"))]
+#[cfg(any(target_os = "macos", target_os = "linux", target_os = "windows", target_os = "netbsd"))]
 fn open_external_url(url: &str) -> Result<()> {
     crate::utils::open_url(url)
 }

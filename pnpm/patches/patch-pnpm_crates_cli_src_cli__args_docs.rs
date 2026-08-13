$NetBSD$

    Support NetBSD.

--- pnpm/crates/cli/src/cli_args/docs.rs.orig	2026-08-12 13:26:25.825803589 +0000
+++ pnpm/crates/cli/src/cli_args/docs.rs
@@ -86,7 +86,7 @@ fn open_url(url: &str) -> miette::Result<()> {
 
 fn open_url(url: &str) -> miette::Result<()> {
     let result = {
-        #[cfg(target_os = "linux")]
+        #[cfg(any(target_os = "linux", target_os = "netbsd"))]
         {
             std::process::Command::new("xdg-open").arg(url).spawn()
         }
@@ -117,7 +117,7 @@ fn open_url(url: &str) -> miette::Result<()> {
             };
             if (result as isize) > 32 { Ok(()) } else { Err(std::io::Error::last_os_error()) }
         }
-        #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows")))]
+        #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows", target_os = "netbsd")))]
         {
             // On unsupported platforms, just print the URL.
             Err(std::io::Error::new(std::io::ErrorKind::Unsupported, "unsupported platform"))

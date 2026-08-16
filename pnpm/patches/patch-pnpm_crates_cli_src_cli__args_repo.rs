$NetBSD$

    Support NetBSD.

--- pnpm/crates/cli/src/cli_args/repo.rs.orig	2026-08-16 06:53:49.097323613 +0000
+++ pnpm/crates/cli/src/cli_args/repo.rs
@@ -393,7 +393,7 @@ fn open_url(url: &str) -> std::io::Result<()> {
 }
 
 fn open_url(url: &str) -> std::io::Result<()> {
-    #[cfg(target_os = "linux")]
+    #[cfg(any(target_os = "linux", target_os = "netbsd"))]
     {
         let status = std::process::Command::new("xdg-open").arg(url).status()?;
         if status.success() { Ok(()) } else { Err(std::io::Error::other("xdg-open failed")) }
@@ -422,7 +422,7 @@ fn open_url(url: &str) -> std::io::Result<()> {
         };
         if (result as isize) > 32 { Ok(()) } else { Err(std::io::Error::last_os_error()) }
     }
-    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows")))]
+    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows", target_os = "netbsd")))]
     {
         Err(std::io::Error::new(std::io::ErrorKind::Unsupported, "unsupported platform"))
     }

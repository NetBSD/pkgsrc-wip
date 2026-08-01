$NetBSD$

Support the Firefox browser integration on the BSDs.

Firefox uses the same ~/.mozilla/native-messaging-hosts location on every
XDG-style unix, and xdg-open is the portable freedesktop handler launcher,
so gate both on "unix except macOS" rather than on Linux.

--- crates/jcode-base/src/browser.rs.orig
+++ crates/jcode-base/src/browser.rs
@@ -677,7 +677,9 @@ fn register_windows_native_host_manifest(manifest_path: &std::path::Path) -> Res
 }
 
 fn native_messaging_hosts_dir() -> Result<PathBuf> {
-    #[cfg(target_os = "linux")]
+    // Firefox uses the same `~/.mozilla/native-messaging-hosts` location on
+    // every XDG-style unix, including the BSDs.
+    #[cfg(all(unix, not(target_os = "macos")))]
     {
         let home = dirs::home_dir().context("No home directory")?;
         Ok(home.join(".mozilla").join("native-messaging-hosts"))
@@ -698,7 +700,7 @@ fn native_messaging_hosts_dir() -> Result<PathBuf> {
         let appdata = dirs::data_dir().context("No app data directory")?;
         Ok(appdata.join("Mozilla").join("NativeMessagingHosts"))
     }
-    #[cfg(not(any(target_os = "linux", target_os = "macos", target_os = "windows")))]
+    #[cfg(not(any(unix, target_os = "windows")))]
     {
         Err(anyhow::anyhow!("Unsupported platform for native messaging"))
     }
@@ -883,7 +885,8 @@ async fn install_extension() -> Result<String> {
         .map_err(|_| anyhow::anyhow!("Could not convert XPI path to file URL: {}", xpi.display()))?
         .to_string();
 
-    #[cfg(target_os = "linux")]
+    // xdg-open is the portable freedesktop handler launcher (Linux and BSDs).
+    #[cfg(all(unix, not(target_os = "macos")))]
     {
         let _ = tokio::process::Command::new("xdg-open")
             .arg(&xpi_url)

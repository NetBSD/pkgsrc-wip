$NetBSD$

Send launch-reminder notifications on the BSDs, as above for notify-send,
and expose the manual setup guidance used by the setup-hotkey fallback.

--- crates/jcode-setup-hints/src/cli_launch_hints.rs.orig
+++ crates/jcode-setup-hints/src/cli_launch_hints.rs
@@ -53,6 +53,25 @@ impl CliSource {
     }
 }
 
+/// Setup guidance for platforms with no automatic global-hotkey install (the
+/// BSDs, for instance).
+///
+/// Hotkey install is compositor-specific, but the Claude/Codex launch
+/// reminders below are plain config-file writes with no platform dependency,
+/// so those are still offered rather than doing nothing.
+#[cfg(not(any(windows, target_os = "macos", target_os = "linux")))]
+pub(super) fn print_manual_platform_setup() {
+    eprintln!("\x1b[1mjcode setup-hotkey\x1b[0m");
+    eprintln!();
+    eprintln!("Automatic global hotkey install is not available on this platform.");
+    eprintln!("Add a keybinding in your desktop environment's keyboard settings:");
+    eprintln!("  - niri: bindings in ~/.config/niri/config.kdl");
+    eprintln!("  - GNOME: Settings > Keyboard > Custom Shortcuts");
+    eprintln!("  - KDE: System Settings > Shortcuts > Custom Shortcuts");
+    eprintln!("  - sway/i3: a `bindsym` line in the compositor config");
+    super::install_cli_launch_hints_notice();
+}
+
 pub(super) fn install_available() -> Result<Vec<String>> {
     let mut installed = Vec::new();
 
@@ -334,7 +353,9 @@ fn send_desktop_notification(title: &str, body: &str) {
             .spawn();
     }
 
-    #[cfg(target_os = "linux")]
+    // libnotify's notify-send is the freedesktop notifier on Linux and the
+    // BSDs alike; gate on "unix minus macOS" so BSD desktops get notices too.
+    #[cfg(all(unix, not(target_os = "macos")))]
     {
         let _ = std::process::Command::new("notify-send")
             .arg("--app-name=jcode")
@@ -372,7 +393,7 @@ fn send_desktop_notification(title: &str, body: &str) {
             .spawn();
     }
 
-    #[cfg(not(any(target_os = "macos", target_os = "linux", windows)))]
+    #[cfg(not(any(unix, windows)))]
     let _ = (title, body);
 }
 

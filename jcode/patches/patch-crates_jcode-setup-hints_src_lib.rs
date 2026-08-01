$NetBSD$

Make "jcode setup-hotkey" useful on platforms without automatic hotkey
installation.

The fallback branch printed "Global hotkey setup is currently only supported
on Windows" and then advised Linux and macOS, which is wrong on both counts,
and it skipped the Claude/Codex launch reminders even though those are plain
config-file writes with no platform dependency. Print accurate guidance and
install the reminders.

Also gate LAUNCH_HOTKEY_TRACKING_VERSION to the platforms that use it, so it
is not dead code elsewhere.

--- crates/jcode-setup-hints/src/lib.rs.orig
+++ crates/jcode-setup-hints/src/lib.rs
@@ -181,6 +181,10 @@ impl Default for SetupHintsState {
 pub const HOTKEY_LISTENER_VERSION: u32 = 6;
 
 /// Current version of generated launch commands carrying learning metadata.
+///
+/// Only meaningful where jcode installs global hotkeys itself (macOS and the
+/// supported Linux compositors); other platforms never write the field.
+#[cfg(any(test, target_os = "macos", target_os = "linux", windows))]
 const LAUNCH_HOTKEY_TRACKING_VERSION: u32 = 1;
 
 /// Maximum number of times we will ever show the terminal/setup nudge prompt
@@ -769,13 +773,7 @@ pub fn run_setup_hotkey(
 
     #[cfg(not(any(windows, target_os = "macos", target_os = "linux")))]
     {
-        eprintln!("Global hotkey setup is currently only supported on Windows.");
-        eprintln!();
-        eprintln!("On Linux/macOS, add a keybinding in your desktop environment:");
-        eprintln!("  - niri: bindings in ~/.config/niri/config.kdl");
-        eprintln!("  - GNOME: Settings > Keyboard > Custom Shortcuts");
-        eprintln!("  - KDE: System Settings > Shortcuts > Custom Shortcuts");
-        eprintln!("  - macOS: Shortcuts.app or System Settings > Keyboard > Shortcuts");
+        cli_launch_hints::print_manual_platform_setup();
         Ok(())
     }
 

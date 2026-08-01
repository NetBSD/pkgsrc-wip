$NetBSD$

Send desktop notifications on the BSDs.

notify-send comes from libnotify and is a freedesktop interface, not a Linux
one, so gate it on "unix except macOS" rather than on Linux.

--- crates/jcode-app-core/src/notifications.rs.orig
+++ crates/jcode-app-core/src/notifications.rs
@@ -329,7 +329,10 @@ pub fn send_desktop_notification_rich(
             .stderr(std::process::Stdio::null())
             .spawn();
     }
-    #[cfg(target_os = "linux")]
+    // notify-send (libnotify) is the freedesktop standard notifier and is
+    // available on Linux and the BSDs alike, so gate on "unix minus macOS"
+    // rather than Linux specifically.
+    #[cfg(all(unix, not(target_os = "macos")))]
     {
         let _ = (subtitle, sound);
         let _ = std::process::Command::new("notify-send")
@@ -341,7 +344,7 @@ pub fn send_desktop_notification_rich(
             .stderr(std::process::Stdio::null())
             .spawn();
     }
-    #[cfg(not(any(target_os = "macos", target_os = "linux")))]
+    #[cfg(not(unix))]
     {
         let _ = (title, subtitle, body, sound);
     }

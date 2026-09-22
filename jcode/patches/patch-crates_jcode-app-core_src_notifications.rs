$NetBSD$

Send desktop notifications on the BSDs.

notify-send comes from libnotify and is a freedesktop interface, not a Linux
one, so gate it on "unix except macOS" rather than on Linux.

--- crates/jcode-app-core/src/notifications.rs.orig
+++ crates/jcode-app-core/src/notifications.rs
@@ -709,7 +709,10 @@
             reap_notification_child(child);
         }
     }
-    #[cfg(target_os = "linux")]
+    // notify-send (libnotify) is the freedesktop standard notifier and is
+    // available on Linux and the BSDs alike, so gate on "unix minus macOS"
+    // rather than Linux specifically.
+    #[cfg(all(unix, not(target_os = "macos")))]
     {
         let _ = (subtitle, sound);
         if let Ok(child) = std::process::Command::new("notify-send")
@@ -724,7 +727,7 @@
             reap_notification_child(child);
         }
     }
-    #[cfg(not(any(target_os = "macos", target_os = "linux")))]
+    #[cfg(not(unix))]
     {
         let _ = (title, subtitle, body, sound);
     }

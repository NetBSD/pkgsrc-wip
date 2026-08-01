$NetBSD$

Use the platform-appropriate stdin-detection tree walk, which now includes
NetBSD, instead of hardcoding the Linux one.

--- crates/jcode-app-core/src/tool/bash.rs.orig
+++ crates/jcode-app-core/src/tool/bash.rs
@@ -802,10 +802,7 @@ impl BashTool {
 
                             let mut request_counter = 0u32;
                             loop {
-                                #[cfg(target_os = "linux")]
-                                let state = stdin_detect::linux::check_process_tree(child_pid);
-                                #[cfg(not(target_os = "linux"))]
-                                let state = stdin_detect::is_waiting_for_stdin(child_pid);
+                                let state = stdin_detect::is_waiting_for_stdin_in_tree(child_pid);
 
                                 if state == StdinState::Reading {
                                     request_counter += 1;

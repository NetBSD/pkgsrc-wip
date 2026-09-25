$NetBSD$

Add NetBSD support.

--- src/collection/processes/unix/process_ext.rs.orig	2026-09-22 06:56:15.000000000 +0200
+++ src/collection/processes/unix/process_ext.rs
@@ -18,7 +18,7 @@
     // and errors are reported via the return value.
     cfg_select! {
         target_os = "freebsd" => unsafe { libc::getpriority(libc::PRIO_PROCESS, pid) },
-        target_os = "macos" => unsafe { libc::getpriority(libc::PRIO_PROCESS, pid as u32) },
+        any(target_os = "macos", target_os = "netbsd") => unsafe { libc::getpriority(libc::PRIO_PROCESS, pid as u32) },
         _ => 0,
     }
 }
@@ -67,6 +67,43 @@
                 0
             }
         }
+        target_os = "netbsd" => {
+            use std::{mem, ptr};
+
+            use libc::{c_int, c_void};
+
+            let mib = [
+                libc::CTL_KERN,
+                libc::KERN_PROC2,
+                libc::KERN_PROC_PID,
+                pid as c_int,
+                mem::size_of::<libc::kinfo_proc2>() as c_int,
+                1,
+            ];
+            let mut kp: libc::kinfo_proc2 = unsafe { mem::zeroed() };
+            let mut size = mem::size_of::<libc::kinfo_proc2>();
+
+            // SAFETY: sysctl takes the following pointer arguments
+            // - mib is valid for KERN_PROC2 with KERN_PROC_PID.
+            // - kp is a properly sized output buffer.
+            // - newp is null for a read-only sysctl.
+            let ret = unsafe {
+                libc::sysctl(
+                    mib.as_ptr(),
+                    mib.len() as u32,
+                    &mut kp as *mut _ as *mut c_void,
+                    &mut size,
+                    ptr::null_mut(),
+                    0,
+                )
+            };
+
+            if ret == 0 {
+                kp.p_priority as i32
+            } else {
+                0
+            }
+        }
         _ => 0,
     }
 }
@@ -264,6 +301,20 @@
                 _ => '?',
             }
         }
+        target_os = "netbsd" => {
+            match status {
+                ProcessStatus::Idle => 'I',
+                ProcessStatus::Run => 'R',
+                ProcessStatus::Sleep => 'S',
+                ProcessStatus::Stop => 'T',
+                ProcessStatus::Zombie => 'Z',
+                ProcessStatus::Dead => 'D',
+                ProcessStatus::LockBlocked => 'L',
+                ProcessStatus::Suspended => 'U',
+                ProcessStatus::Tracing => 'X',
+                _ => '?',
+            }
+        }
         _ => '?',
     }
 }

$NetBSD$

Add NetBSD support.

--- src/collection/processes.rs.orig	2026-09-22 06:56:15.000000000 +0200
+++ src/collection/processes.rs
@@ -186,6 +186,7 @@
             any(
                 target_os = "freebsd",
                 target_os = "macos",
+                target_os = "netbsd",
                 target_os = "windows",
                 target_os = "android",
                 target_os = "ios"
@@ -224,7 +225,7 @@
             ProcessStatus::Zombie => "Zombie",
             _ => "Unknown",
         },
-        target_os = "freebsd" => match status {
+        any(target_os = "freebsd", target_os = "netbsd") => match status {
             ProcessStatus::Idle => "Idle",
             ProcessStatus::Run => "Runnable",
             ProcessStatus::Sleep => "Sleeping",
@@ -232,6 +233,8 @@
             ProcessStatus::Zombie => "Zombie",
             ProcessStatus::Dead => "Dead",
             ProcessStatus::LockBlocked => "LockBlocked",
+            ProcessStatus::Suspended => "Suspended",
+            ProcessStatus::Tracing => "Tracing",
             _ => "Unknown",
         },
         _ => "Unknown",

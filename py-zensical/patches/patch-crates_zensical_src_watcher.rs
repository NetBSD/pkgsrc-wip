$NetBSD$

https://github.com/zensical/zensical/pull/696

--- crates/zensical/src/watcher.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ crates/zensical/src/watcher.rs
@@ -28,6 +28,7 @@ use std::collections::BTreeSet;
 use crossbeam::channel::Sender;
 use mio::Waker;
 use std::collections::BTreeSet;
+use std::ffi::OsStr;
 use std::fs;
 use std::path::{Path, PathBuf};
 use std::sync::Arc;
@@ -227,7 +228,24 @@ impl Watcher {
         // Watch docs and template directories
         agent.watch(&config.path)?;
         for theme_dir in &config.theme_dirs {
-            agent.watch(theme_dir)?;
+            // Skip `.icons` directory. On NetBSD, inotify uses the kqueue
+            // backend which opens one file descriptor per file/directory,
+            // quickly reaching any file descriptor limit set on the system.
+            match fs::read_dir(theme_dir) {
+                Ok(entries) => {
+                    for entry in entries.flatten() {
+                        let path = entry.path();
+                        if path.file_name() != Some(OsStr::new(".icons")) {
+                            agent.watch(&path)?;
+                        }
+                    }
+                }
+                Err(_) => {
+                    // Fall back to watching the whole theme directory if we
+                    // cannot enumerate its contents for any reason.
+                    agent.watch(theme_dir)?;
+                }
+            }
         }
 
         // Watch files used by extensions

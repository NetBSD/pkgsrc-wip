$NetBSD$

* Use 'patch' instead of 'git' to apply patches

--- ../boring-signal/boring-sys/build/main.rs.orig	2026-08-06 19:21:54.000000000 +0200
+++ ../boring-signal/boring-sys/build/main.rs	2026-11-17 15:48:32.727559003 +0100
@@ -487,9 +487,7 @@
     lock_file.lock()?;
 
     // NOTE: init git in the copied files, so we can apply patches
-    if !has_git {
-        run_command(Command::new("git").arg("init").current_dir(src_path))?;
-    }
+    let _ = has_git;
 
     if config.features.allow_crl_extensions_bad_version {
         println!(
@@ -532,16 +530,13 @@
     #[cfg(windows)]
     let cmd_path = config.manifest_dir.join("patches").join(patch_name);
 
-    let mut args = vec!["apply", "-v", "--whitespace=fix"];
-
     // non-bazel versions of BoringSSL have no src/ dir
-    if config.is_bazel {
-        args.push("-p2");
-    }
+    let strip = if config.is_bazel { "-p2" } else { "-p1" };
 
     run_command(
-        Command::new("git")
-            .args(&args)
+        Command::new("patch")
+            .arg(strip)
+            .arg("-i")
             .arg(cmd_path)
             .current_dir(src_path),
     )?;

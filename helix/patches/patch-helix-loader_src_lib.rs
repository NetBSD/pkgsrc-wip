$NetBSD$

Taken from FreeBSD ports, original patch by ashish@.

--- helix-loader/src/lib.rs.orig	2025-11-01 21:44:24.442453555 +0000
+++ helix-loader/src/lib.rs
@@ -49,9 +49,6 @@ fn prioritize_runtime_dirs() -> Vec<Path
         rt_dirs.push(path);
     }
 
-    let conf_rt_dir = config_dir().join(RT_DIR);
-    rt_dirs.push(conf_rt_dir);
-
     if let Ok(dir) = std::env::var("HELIX_RUNTIME") {
         let dir = path::expand_tilde(Path::new(&dir));
         rt_dirs.push(path::normalize(dir));

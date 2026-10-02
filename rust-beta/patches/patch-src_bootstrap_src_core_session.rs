$NetBSD$

Don't filter out optimization flags.
FreeBSD has a particular C++ runtime library name.
Don't assume files in ${PREFIX}/lib are readable by the building user.

--- src/bootstrap/src/core/session.rs.orig	2026-10-01 18:00:50.836508285 +0000
+++ src/bootstrap/src/core/session.rs
@@ -1024,7 +1024,6 @@ impl Session {
         base.args()
             .iter()
             .map(|s| s.to_string_lossy().into_owned())
-            .filter(|s| !s.starts_with("-O") && !s.starts_with("/O"))
             .collect::<Vec<String>>()
     }
 
@@ -1035,7 +1034,8 @@ impl Session {
         // If we're compiling C++ on macOS then we add a flag indicating that
         // we want libc++ (more filled out than libstdc++), ensuring that
         // LLVM/etc are all properly compiled.
-        if matches!(c, CLang::Cxx) && target.contains("apple-darwin") {
+        if matches!(c, CLang::Cxx) &&
+            (target.contains("apple-darwin") || target.contains("freebsd")) {
             base.push("-stdlib=libc++".into());
         }
 
@@ -1559,7 +1559,12 @@ impl Session {
             // but if that fails just fall back to a slow `copy` operation.
         } else {
             if let Err(e) = fs::copy(&src, dst) {
-                panic!("failed to copy `{}` to `{}`: {}", src.display(), dst.display(), e)
+                if e.kind() == io::ErrorKind::PermissionDenied {
+                    eprintln!("Skipping copy of `{}` to `{}`: {}", src.display(), dst.display(), e);
+                    return;
+                } else {
+                    panic!("failed to copy `{}` to `{}`: {}", src.display(), dst.display(), e)
+                }
             }
             t!(fs::set_permissions(dst, metadata.permissions()));
 

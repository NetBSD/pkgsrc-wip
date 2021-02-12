$NetBSD: patch-src_bootstrap_compile.rs,v 1.1 2020/03/14 08:02:46 jperkin Exp $

On Darwin, do not use @rpath for internal libraries.

--- src/bootstrap/compile.rs.orig	2021-02-10 17:36:44.000000000 +0000
+++ src/bootstrap/compile.rs
@@ -359,7 +359,7 @@ fn copy_sanitizers(
             // Update the library install name reflect the fact it has been renamed.
             let status = Command::new("install_name_tool")
                 .arg("-id")
-                .arg(format!("@rpath/{}", runtime.name))
+                .arg(format!("@PREFIX@/lib/{}", runtime.name))
                 .arg(&dst)
                 .status()
                 .expect("failed to execute `install_name_tool`");

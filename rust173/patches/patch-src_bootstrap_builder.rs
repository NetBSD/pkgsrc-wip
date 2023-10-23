$NetBSD: patch-src_bootstrap_builder.rs,v 1.11 2020/07/06 13:56:32 he Exp $

Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/builder.rs.orig	2023-10-03 02:52:17.000000000 +0000
+++ src/bootstrap/builder.rs
@@ -1637,7 +1637,7 @@ impl<'a> Builder<'a> {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.contains("windows") && !target.contains("aix") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/lib"))
             } else {
                 None
             };

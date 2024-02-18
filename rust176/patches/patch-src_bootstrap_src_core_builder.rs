$NetBSD$

Use @PREFIX@, not $ORIGIN in rpath.

--- src/bootstrap/src/core/builder.rs.orig	2024-02-04 13:18:05.000000000 +0000
+++ src/bootstrap/src/core/builder.rs
@@ -1687,7 +1687,7 @@ impl<'a> Builder<'a> {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.is_windows() && !target.contains("aix") && !target.contains("xous") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/{libdir}"))
             } else {
                 None
             };

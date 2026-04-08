$NetBSD$

Find external libunwind and libLLVM in pkgsrc (not just Linux).
Use @PREFIX@ in rpath.

--- src/bootstrap/src/core/builder/cargo.rs.orig	2026-04-08 12:20:36.460289424 +0000
+++ src/bootstrap/src/core/builder/cargo.rs
@@ -299,7 +299,7 @@ impl Cargo {
                 && !target.contains("xous")
             {
                 self.rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,@PREFIX@/lib"))
             } else {
                 None
             };
@@ -1421,6 +1421,9 @@ impl Builder<'_> {
                     (_, false) => Some("dev"),
                 }
             };
+
+        // added for pkgsrc libunwind or external LLVM
+        rustflags.arg("-Clink-args=-Wl,-rpath,@PREFIX@/lib,-L@PREFIX@/lib");
 
         Cargo {
             command: cargo,

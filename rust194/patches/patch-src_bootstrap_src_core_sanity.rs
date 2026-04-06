$NetBSD$

Temporarily add m68k-unknown-netbsd to STAGE0_MISSING_TARGETS.
...while we bootstrap the target, and don't make the presence
while it's a known target a fatal error.

--- src/bootstrap/src/core/sanity.rs.orig	2026-03-02 23:18:25.000000000 +0000
+++ src/bootstrap/src/core/sanity.rs
@@ -38,6 +38,7 @@ pub struct Finder {
 const STAGE0_MISSING_TARGETS: &[&str] = &[
     // just a dummy comment so the list doesn't get onelined
     "riscv64im-unknown-none-elf",
+    "m68k-unknown-netbsd",
 ];
 
 /// Minimum version threshold for libstdc++ required when using prebuilt LLVM
@@ -266,7 +267,10 @@ than building it.
                 for duplicated_target in duplicated_targets {
                     println!("  {duplicated_target}");
                 }
-                std::process::exit(1);
+// For now don't make this a fatal error.
+// e.g. m68k-unknown-netbsd may be in the list for a while
+// until LLVM is fixed to not emit 16-bit PC-relative relocations only...
+//              std::process::exit(1);
             }
 
             // Check if it's a built-in target.

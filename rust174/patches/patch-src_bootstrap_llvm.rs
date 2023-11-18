$NetBSD$

Add NetBSD to the list of riscv's which don't need -latomic.
Try to force use of -latomic on mips* on NetBSD.

--- src/bootstrap/llvm.rs.orig	2023-08-03 12:13:07.000000000 +0000
+++ src/bootstrap/llvm.rs
@@ -396,6 +396,13 @@ impl Step for Llvm {
             ldflags.shared.push(" -latomic");
         }
 
+        if target.starts_with("mips") && target.contains("netbsd")
+        {
+            // try to force this here, should possibly go elsewhere...
+            ldflags.exe.push(" -latomic");
+            ldflags.shared.push(" -latomic");
+        }
+
         if target.contains("msvc") {
             cfg.define("LLVM_USE_CRT_DEBUG", "MT");
             cfg.define("LLVM_USE_CRT_RELEASE", "MT");

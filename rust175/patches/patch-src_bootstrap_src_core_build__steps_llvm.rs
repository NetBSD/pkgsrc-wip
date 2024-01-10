$NetBSD$

Force use of -latomic on mips* on NetBSD.

--- src/bootstrap/src/core/build_steps/llvm.rs.orig	2024-01-06 20:59:17.436053488 +0000
+++ src/bootstrap/src/core/build_steps/llvm.rs
@@ -402,6 +402,13 @@ impl Step for Llvm {
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

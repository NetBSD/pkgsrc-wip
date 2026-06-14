$NetBSD$

Enable PIE.

--- build.zig.orig	2026-04-16 19:43:57.000000000 +0000
+++ build.zig
@@ -217,6 +217,7 @@ pub fn build(b: *Build) !void {
             .use_llvm = use_llvm,
             .use_lld = use_llvm,
         });
+        exe.pie = pie;
         b.installArtifact(exe);
     }
 

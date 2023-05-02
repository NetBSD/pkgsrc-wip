From 23fdbe052d06d186c5b63d930055344c848e0259 Mon Sep 17 00:00:00 2001
From: Michael Dusan <michael.dusan@gmail.com>
Date: Sat, 29 Apr 2023 13:14:49 -0400
Subject: [PATCH] netbsd: restrict PT_LOAD workaround to dlibs only

NetBSD supports executables with > 2 PT_LOAD segments but dynamic
libraries continue to expect exactly 2 PT_LOAD segments.

--- src/link/Elf.zig
+++ src/link/Elf.zig
@@ -1636,10 +1636,10 @@ fn linkWithLLD(self: *Elf, comp: *Compilation, prog_node: *std.Progress.Node) !v
             try argv.append("-pie");
         }
 
-        if (self.base.options.link_mode == .Dynamic and target.os.tag == .netbsd) {
+        if (is_dyn_lib and target.os.tag == .netbsd) {
             // Add options to produce shared objects with only 2 PT_LOAD segments.
             // NetBSD expects 2 PT_LOAD segments in a shared object, otherwise
-            // ld.elf_so fails to load, emitting a general "not found" error.
+            // ld.elf_so fails loading dynamic libraries with "not found" error.
             // See https://github.com/ziglang/zig/issues/9109 .
             try argv.append("--no-rosegment");
             try argv.append("-znorelro");

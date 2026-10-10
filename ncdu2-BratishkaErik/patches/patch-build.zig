$NetBSD$

Help it find zstd.h (and libzstd, perhaps not needed).

--- build.zig.orig	2026-10-03 18:44:07.000000000 +0000
+++ build.zig
@@ -52,6 +52,16 @@ pub fn build(b: *std.Build) void {
         t.addIncludePath(ncurses.inst_dir.path(b, "include"));
         main_mod.addObjectFile(ncurses.inst_dir.path(b, "lib/libncursesw.a"));
     }
+    const include_path: std.Build.LazyPath = .{
+        .cwd_relative = "/usr/pkg/include",
+    };
+
+    const library_path: std.Build.LazyPath = .{
+        .cwd_relative = "/usr/pkg/lib",
+    };
+
+    translate_c.addIncludePath(include_path);
+    main_mod.addLibraryPath(library_path);
 
     if (!use_system_zstd) zstd: {
         // These are settings used by release process

$NetBSD$

Help it find zstd.h (and libzstd, perhaps not needed).

--- build.zig.orig	2026-10-05 15:29:52.502307458 +0000
+++ build.zig
@@ -52,6 +52,16 @@ pub fn build(b: *std.Build) void {
         .target = target,
         .optimize = optimize,
     });
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
     main_mod.addImport("c", translate_c.createModule());
 
     const exe = b.addExecutable(.{

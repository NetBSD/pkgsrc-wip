$NetBSD$

Don't make assumptions about mask data type (which is sigset_t on NetBSD).

--- src/Mepo.zig.orig	2022-05-09 19:01:26.000000000 +0000
+++ src/Mepo.zig
@@ -1314,7 +1314,7 @@ pub fn init(allocator: std.mem.Allocator
         for (sigs) |sig| {
             std.os.sigaction(sig, &.{
                 .handler = .{ .handler = sighandle_terminate },
-                .mask = [_]u32{0} ** 32,
+                .mask = std.os.empty_sigset,
                 .flags = @as(c_uint, 0),
             }, null);
         }

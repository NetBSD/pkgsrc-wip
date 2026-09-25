$NetBSD$

Bind getmntinfo to __getmntinfo90 to match the NetBSD 9+ statvfs layout that
the patched libc crate (rust-lang/libc#5243) uses; __getmntinfo13 returns the
old layout and makes sysinfo skip every mount, so bottom shows no disks.

--- ../vendor/sysinfo-0.39.6/src/unix/bsd/netbsd/ffi.rs.orig	2026-09-25 08:51:47.733295427 +0200
+++ ../vendor/sysinfo-0.39.6/src/unix/bsd/netbsd/ffi.rs
@@ -232,7 +232,10 @@
     // The `#[link_name = "__getmntinfo13"]` on `getmntinfo` was accidentally
     // dropped in libc 0.2.174 and restored by rust-lang/libc#5251.
     // Can be removed once libc makes a new release.
-    #[link_name = "__getmntinfo13"]
+    // pkgsrc: the libc crate in this build carries the NetBSD 9+ statvfs
+    // layout (rust-lang/libc#5243), so bind the matching __getmntinfo90
+    // symbol; __getmntinfo13 returns the pre-9 layout and yields no disks.
+    #[link_name = "__getmntinfo90"]
     pub(crate) fn getmntinfo(mntbufp: *mut *mut libc::statvfs, flags: c_int) -> c_int;
 
     // Reads the user-preferred display block size (BLOCKSIZE env var, or the

$NetBSD$

Apply https://github.com/rust-lang/libc/pull/4265/files
to fix getmntinfo() from rust.

--- vendor/libc-0.2.168/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2025-04-05 11:35:20.818765987 +0000
+++ vendor/libc-0.2.168/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2850,6 +2850,7 @@ extern "C" {
         hint: *const c_void,
     ) -> c_int;
 
+    #[link_name = "__getmntinfo13"]
     pub fn getmntinfo(mntbufp: *mut *mut crate::statvfs, flags: c_int) -> c_int;
     pub fn getvfsstat(buf: *mut statvfs, bufsize: size_t, flags: c_int) -> c_int;
 }

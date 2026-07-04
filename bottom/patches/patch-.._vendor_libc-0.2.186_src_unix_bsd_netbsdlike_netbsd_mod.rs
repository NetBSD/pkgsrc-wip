$NetBSD$

Upstream patch: https://github.com/rust-lang/libc/pull/5243

--- ../vendor/libc-0.2.186/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2026-07-04 11:20:16.886076859 +0000
+++ ../vendor/libc-0.2.186/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2206,6 +2206,7 @@ extern "C" {
         ntargets: size_t,
         hint: *const c_void,
     ) -> c_int;
+    #[link_name = "__getmntinfo90"]
     pub fn getmntinfo(mntbufp: *mut *mut crate::statvfs, flags: c_int) -> c_int;
     pub fn getvfsstat(buf: *mut crate::statvfs, bufsize: size_t, flags: c_int) -> c_int;
 

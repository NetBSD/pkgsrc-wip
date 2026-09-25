$NetBSD$

Upstream patch: https://github.com/rust-lang/libc/pull/5243
(libc 0.2.189 still ships the pre-NetBSD 9 statvfs layout and binds
getmntinfo to the __getmntinfo13 compat symbol; NetBSD 10/11 need
the 190/90 versions, see NetBSD sys/statvfs.h.)

--- ../vendor/libc-0.2.189/src/unix/bsd/netbsdlike/netbsd/mod.rs.orig	2006-07-24 03:21:28.000000000 +0200
+++ ../vendor/libc-0.2.189/src/unix/bsd/netbsdlike/netbsd/mod.rs
@@ -2250,7 +2250,7 @@
         ntargets: size_t,
         hint: *const c_void,
     ) -> c_int;
-    #[link_name = "__getmntinfo13"]
+    #[link_name = "__getmntinfo90"]
     pub fn getmntinfo(mntbufp: *mut *mut crate::statvfs, flags: c_int) -> c_int;
     pub fn getvfsstat(buf: *mut crate::statvfs, bufsize: size_t, flags: c_int) -> c_int;
 

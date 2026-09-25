$NetBSD$

Upstream patch: https://github.com/rust-lang/libc/pull/5243
(libc 0.2.189 still ships the pre-NetBSD 9 statvfs layout and binds
getmntinfo to the __getmntinfo13 compat symbol; NetBSD 10/11 need
the 190/90 versions, see NetBSD sys/statvfs.h.)

--- ../vendor/libc-0.2.189/src/unix/mod.rs.orig	2006-07-24 03:21:28.000000000 +0200
+++ ../vendor/libc-0.2.189/src/unix/mod.rs
@@ -1611,8 +1611,10 @@
     pub fn sem_trywait(sem: *mut sem_t) -> c_int;
     pub fn sem_post(sem: *mut sem_t) -> c_int;
     #[cfg_attr(gnu_file_offset_bits64, link_name = "statvfs64")]
+    #[cfg_attr(target_os = "netbsd", link_name = "__statvfs190")]
     pub fn statvfs(path: *const c_char, buf: *mut crate::statvfs) -> c_int;
     #[cfg_attr(gnu_file_offset_bits64, link_name = "fstatvfs64")]
+    #[cfg_attr(target_os = "netbsd", link_name = "__fstatvfs190")]
     pub fn fstatvfs(fd: c_int, buf: *mut crate::statvfs) -> c_int;
 
     #[cfg_attr(target_os = "netbsd", link_name = "__sigemptyset14")]

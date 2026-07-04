$NetBSD$

Upstream patch: https://github.com/rust-lang/libc/pull/5243

--- ../vendor/libc-0.2.186/src/unix/mod.rs.orig	2026-07-04 11:20:16.882281039 +0000
+++ ../vendor/libc-0.2.186/src/unix/mod.rs
@@ -1567,8 +1567,10 @@ extern "C" {
     pub fn sem_trywait(sem: *mut sem_t) -> c_int;
     pub fn sem_post(sem: *mut sem_t) -> c_int;
     #[cfg_attr(gnu_file_offset_bits64, link_name = "statvfs64")]
+    #[cfg_attr(target_os = "netbsd", link_name = "__statvfs190")]
     pub fn statvfs(path: *const c_char, buf: *mut crate::statvfs) -> c_int;
     #[cfg_attr(gnu_file_offset_bits64, link_name = "fstatvfs64")]
+    #[cfg_attr(target_os = "netbsd", link_name = "__fstatvfs190")]
     pub fn fstatvfs(fd: c_int, buf: *mut crate::statvfs) -> c_int;
 
     #[cfg_attr(target_os = "netbsd", link_name = "__sigemptyset14")]

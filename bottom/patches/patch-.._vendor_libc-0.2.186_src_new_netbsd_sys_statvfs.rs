$NetBSD$

Upstream patch: https://github.com/rust-lang/libc/pull/5243

--- ../vendor/libc-0.2.186/src/new/netbsd/sys/statvfs.rs.orig	2026-07-04 11:20:16.859754761 +0000
+++ ../vendor/libc-0.2.186/src/new/netbsd/sys/statvfs.rs
@@ -35,13 +35,11 @@ s! {
         pub f_namemax: c_ulong,
         pub f_owner: crate::uid_t,
 
-        // This type is updated in a future version
-        f_spare: [u32; 4],
+        f_spare: [u64; 4],
 
         pub f_fstypename: [c_char; _VFS_NAMELEN],
         pub f_mntonname: [c_char; _VFS_MNAMELEN],
         pub f_mntfromname: [c_char; _VFS_MNAMELEN],
-        // Added in NetBSD10
-        // pub f_mntfromlabel: [c_char; _VFS_MNAMELEN],
+        pub f_mntfromlabel: [c_char; _VFS_MNAMELEN],
     }
 }

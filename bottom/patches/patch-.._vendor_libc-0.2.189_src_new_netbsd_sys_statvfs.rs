$NetBSD$

Upstream patch: https://github.com/rust-lang/libc/pull/5243
(libc 0.2.189 still ships the pre-NetBSD 9 statvfs layout and binds
getmntinfo to the __getmntinfo13 compat symbol; NetBSD 10/11 need
the 190/90 versions, see NetBSD sys/statvfs.h.)

--- ../vendor/libc-0.2.189/src/new/netbsd/sys/statvfs.rs.orig	2006-07-24 03:21:28.000000000 +0200
+++ ../vendor/libc-0.2.189/src/new/netbsd/sys/statvfs.rs
@@ -35,13 +35,11 @@
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

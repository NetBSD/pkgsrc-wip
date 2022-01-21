$NetBSD$

NetBSD does not implement statfs(2).

--- dlls/ntdll/unix/file.c.orig	2022-01-07 21:03:02.000000000 +0000
+++ dlls/ntdll/unix/file.c
@@ -6524,7 +6524,11 @@ NTSTATUS WINAPI NtQueryVolumeInformation
         if (!get_mountmgr_fs_info( handle, fd, &drive, sizeof(drive) )) fs_type = drive.fs_type;
         else
         {
+#if defined(__NetBSD__)
+            struct statvfs stfs;
+#else
             struct statfs stfs;
+#endif
 
             if (!fstatfs( fd, &stfs ))
             {
@@ -6541,7 +6545,8 @@ NTSTATUS WINAPI NtQueryVolumeInformation
                     fs_type = MOUNTMGR_FS_TYPE_FAT32;
                     break;
                 }
-#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
+#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__) || \
+      defined(__NetBSD__)
                 if (!strcmp( stfs.f_fstypename, "cd9660" ))
                     fs_type = MOUNTMGR_FS_TYPE_ISO9660;
                 else if (!strcmp( stfs.f_fstypename, "udf" ))

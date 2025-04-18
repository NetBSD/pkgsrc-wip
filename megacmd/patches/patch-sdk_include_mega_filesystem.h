$NetBSD$

* Add BSD supported filesystems

--- sdk/include/mega/filesystem.h.orig	2025-04-17 16:17:57.087434545 +0200
+++ sdk/include/mega/filesystem.h
@@ -51,6 +51,10 @@ enum FileSystemType
     FS_SMB = 12,
     FS_SMB2 = 13,
     FS_LIFS = 14,
+    FS_FFS = 15,
+    FS_HAMMER = 16,
+    FS_UFS = 17,
+    FS_ZFS = 18,
 };
 
 typedef void (*asyncfscallback)(void *);

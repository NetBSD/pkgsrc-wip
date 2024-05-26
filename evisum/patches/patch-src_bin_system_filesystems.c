$NetBSD$

stat arguments are named differently.

--- src/bin/system/filesystems.c.orig	2024-05-21 11:39:11.067056732 +0000
+++ src/bin/system/filesystems.c
@@ -73,7 +73,11 @@ file_system_info_all_get(void)
      }
    fclose(f);
 # else
+#if defined(__NetBSD__)
+   struct statvfs *mounts;
+#else
    struct statfs *mounts;
+#endif
    int i, count;

    count = getmntinfo(&mounts, MNT_WAIT);
@@ -82,7 +86,7 @@ file_system_info_all_get(void)
         File_System *fs = calloc(1, sizeof(File_System));
         fs->mount = strdup(mounts[i].f_mntonname);
         fs->path  = strdup(mounts[i].f_mntfromname);
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) | defined(__NetBSD__)
 #else
         fs->type  = mounts[i].f_type;
 #endif

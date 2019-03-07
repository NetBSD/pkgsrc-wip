$NetBSD$

--- src/libraries/physfs/physfs_platform_unix.c.orig	2019-03-06 18:03:19.940432285 -0800
+++ src/libraries/physfs/physfs_platform_unix.c	2019-03-06 18:04:27.934900028 -0800
@@ -79,7 +79,13 @@
 
 #elif (defined PHYSFS_HAVE_SYS_UCRED_H)
     int i;
+
+#if __NetBSD__
+    struct statvfs *mntbufp = NULL;
+#else
     struct statfs *mntbufp = NULL;
+#endif
+
     int mounts = getmntinfo(&mntbufp, MNT_NOWAIT);
 
     for (i = 0; i < mounts; i++)

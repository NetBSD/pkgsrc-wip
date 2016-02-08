$NetBSD$

--- src/Native/System.Native/pal_mount.cpp.orig	2016-02-07 13:49:29.000000000 +0000
+++ src/Native/System.Native/pal_mount.cpp
@@ -22,7 +22,11 @@ static int32_t GetMountInfo(MountPointFo
 {
 #if HAVE_MNTINFO
     // getmntinfo returns pointers to OS-internal structs, so we don't need to worry about free'ing the object
+#if HAVE_SYS_STATVFS
+    struct statvfs* mounts = nullptr;
+#else
     struct statfs* mounts = nullptr;
+#endif
     int count = getmntinfo(&mounts, 0);
     for (int32_t i = 0; i < count; i++)
     {
@@ -68,8 +72,13 @@ extern "C" int32_t SystemNative_GetSpace
     assert(name != nullptr);
     assert(mpi != nullptr);
 
-    struct statfs stats = {};
+#if HAVE_SYS_STATVFS
+    struct statvfs stats = {};
+    int result = statvfs(name, &stats);
+#else
+    struct statvfs stats = {};
     int result = statfs(name, &stats);
+#endif
     if (result == 0)
     {
         // Note that these have signed integer types on some platforms but musn't be negative.
@@ -98,13 +107,22 @@ SystemNative_GetFormatInfoForMountPoint(
     assert((formatNameBuffer != nullptr) && (formatType != nullptr));
     assert(bufferLength > 0);
 
+#if HAVE_SYS_STATVFS
+    struct statvfs stats;
+    int result = statvfs(name, &stats);
+#else
     struct statfs stats;
     int result = statfs(name, &stats);
+#endif
     if (result == 0)
     {
 
 #if HAVE_STATFS_FSTYPENAME
+#if HAVE_VFS_NAMELEN
+        if (bufferLength < VFS_NAMELEN)
+#else
         if (bufferLength < MFSNAMELEN)
+#endif
         {
             result = ERANGE;
             *formatType = 0;

$NetBSD$

--- src/VBox/Runtime/r3/posix/fs-posix.cpp.orig	2016-03-04 19:30:03.000000000 +0000
+++ src/VBox/Runtime/r3/posix/fs-posix.cpp
@@ -35,7 +35,7 @@
 #ifdef RT_OS_LINUX
 # include <mntent.h>
 #endif
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/mount.h>
 #endif
 
@@ -311,6 +311,31 @@ RTR3DECL(int) RTFsQueryType(const char *
             }
             else
                 rc = RTErrConvertFromErrno(errno);
+
+#elif defined(RT_OS_NETBSD)
+            struct statvfs statfsBuf;
+            if (!statvfs(pszNativeFsPath, &statfsBuf))
+            {
+                if (!strcmp("hfs", statfsBuf.f_fstypename))
+                    *penmType = RTFSTYPE_HFS;
+                else if (   !strcmp("fat", statfsBuf.f_fstypename)
+                         || !strcmp("msdos", statfsBuf.f_fstypename))
+                    *penmType = RTFSTYPE_FAT;
+                else if (!strcmp("ntfs", statfsBuf.f_fstypename))
+                    *penmType = RTFSTYPE_NTFS;
+                else if (!strcmp("autofs", statfsBuf.f_fstypename))
+                    *penmType = RTFSTYPE_AUTOFS;
+                else if (!strcmp("devfs", statfsBuf.f_fstypename))
+                    *penmType = RTFSTYPE_DEVFS;
+                else if (!strcmp("nfs", statfsBuf.f_fstypename))
+                    *penmType = RTFSTYPE_NFS;
+                else if (!strcmp("ufs", statfsBuf.f_fstypename))
+                    *penmType = RTFSTYPE_UFS;
+                else if (!strcmp("zfs", statfsBuf.f_fstypename))
+                    *penmType = RTFSTYPE_ZFS;
+            }
+            else
+                rc = RTErrConvertFromErrno(errno);
 #endif
         }
         else

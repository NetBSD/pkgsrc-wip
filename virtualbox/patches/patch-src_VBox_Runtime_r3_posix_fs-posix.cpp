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
 
@@ -287,7 +287,7 @@ RTR3DECL(int) RTFsQueryType(const char *
             else if (!strcmp("nfs", Stat.st_fstype))
                 *penmType = RTFSTYPE_NFS;
 
-#elif defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
             struct statfs statfsBuf;
             if (!statfs(pszNativeFsPath, &statfsBuf))
             {

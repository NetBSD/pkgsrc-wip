$NetBSD$

--- src/VBox/ImageMounter/VBoxFUSE/VBoxFUSE.cpp.orig	2016-03-04 19:29:32.000000000 +0000
+++ src/VBox/ImageMounter/VBoxFUSE/VBoxFUSE.cpp
@@ -22,7 +22,7 @@
 #define LOG_GROUP LOG_GROUP_DEFAULT /** @todo log group */
 #include <iprt/types.h>
 
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_NETBSD)
 # include <sys/param.h>
 # undef PVM     /* Blasted old BSD mess still hanging around darwin. */
 #endif
@@ -1013,7 +1013,7 @@ static int vboxfuseOp_open(const char *p
         return -EINVAL;
     if ((pInfo->flags & O_ACCMODE) == O_ACCMODE)
         return -EINVAL;
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
     if (pInfo->flags & (  O_APPEND | O_ASYNC | O_DIRECT /* | O_LARGEFILE ? */
                         | O_NOCTTY | O_NOFOLLOW | O_NONBLOCK
                         /* | O_SYNC ? */))
@@ -1473,4 +1473,3 @@ int main(int argc, char **argv)
     RTPrintf("VBoxFUSE: fuse_main -> %d\n", rc);
     return rc;
 }
-

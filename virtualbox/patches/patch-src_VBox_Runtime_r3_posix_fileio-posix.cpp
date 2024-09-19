$NetBSD$

--- src/VBox/Runtime/r3/posix/fileio-posix.cpp.orig	2016-03-04 19:30:03.000000000 +0000
+++ src/VBox/Runtime/r3/posix/fileio-posix.cpp
@@ -48,7 +48,7 @@
 #if defined(RT_OS_OS2) && (!defined(__INNOTEK_LIBC__) || __INNOTEK_LIBC__ < 0x006)
 # include <io.h>
 #endif
-#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD)
+#if defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
 # include <sys/disk.h>
 #endif
 #ifdef RT_OS_SOLARIS
@@ -154,7 +154,7 @@ RTR3DECL(int) RTFileOpen(PRTFILE pFile, 
     if (fOpen & RTFILE_O_ASYNC_IO)
         fOpenMode |= O_DIRECT;
 #endif
-#if defined(O_DIRECT) && (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD))
+#if defined(O_DIRECT) && (defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)|| defined(RT_OS_NETBSD))
     /* Disable the kernel cache. */
     if (fOpen & RTFILE_O_NO_CACHE)
         fOpenMode |= O_DIRECT;
@@ -559,7 +559,7 @@ RTR3DECL(int) RTFileGetSize(RTFILE hFile
         if (   st.st_size != 0
 #if defined(RT_OS_SOLARIS)
             || (!S_ISBLK(st.st_mode) && !S_ISCHR(st.st_mode))
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
             || !S_ISCHR(st.st_mode)
 #else
             || !S_ISBLK(st.st_mode)
@@ -595,7 +595,7 @@ RTR3DECL(int) RTFileGetSize(RTFILE hFile
         if (errno == EINVAL || errno == ENOTTY)
             return VINF_SUCCESS;
 
-#elif defined(RT_OS_FREEBSD)
+#elif defined(RT_OS_FREEBSD) || defined(RT_OS_NETBSD)
         off_t cbMedia = 0;
         if (!ioctl(RTFileToNative(hFile), DIOCGMEDIASIZE, &cbMedia))
         {
@@ -743,4 +743,3 @@ RTR3DECL(int) RTFileRename(const char *p
              pszSrc, pszSrc, pszDst, pszDst, fRename, rc));
     return rc;
 }
-

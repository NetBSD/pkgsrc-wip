$NetBSD$

--- src/lib/eina/eina_file_posix.c.orig	2023-12-23 15:56:36.000000000 +0000
+++ src/lib/eina/eina_file_posix.c
@@ -1299,6 +1299,16 @@ typedef struct
    unsigned char  ____pad[4];
    char           d_name[4096];
 } Dirent;
+#elif defined(__NetBSD__)
+# define do_getdents(fd, buf, size) getdents(fd, buf, size)
+typedef struct
+{
+   ino_t          d_fileno;
+   uint16_t       d_reclen;
+   uint16_t       d_namlen;
+   uint8_t        d_type;
+   char           d_name[4096];
+} Dirent;
 #elif defined(__linux__)
 # define do_getdents(fd, buf, size) syscall(SYS_getdents64, fd, buf, size)
 // getdents64 added un glibc 2.30 ... so use raw syscall - will work
@@ -1322,7 +1332,7 @@ eina_file_close_from(int fd, int *except
 #else
 #ifdef HAVE_DIRENT_H
 //# if 0
-# if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__linux__)
+# if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__linux__)
    int dirfd;
    Dirent *d;
    char buf[4096 + 128];

$NetBSD$

Add getdents wrapper. Use NetBSD dirent structure.
Merged upstream: https://git.enlightenment.org/enlightenment/efl/pulls/130

--- src/lib/eina/eina_file_posix.c.orig	2025-03-17 15:43:43.000000000 +0000
+++ src/lib/eina/eina_file_posix.c
@@ -1285,6 +1285,9 @@ typedef struct
    unsigned char  ____pad[4];
    char           d_name[4096];
 } Dirent;
+#elif defined(__NetBSD__)
+# define do_getdents(fd, buf, size) getdents(fd, buf, size)
+typedef struct dirent Dirent;
 #elif defined(__linux__)
 # define do_getdents(fd, buf, size) syscall(SYS_getdents64, fd, buf, size)
 // getdents64 added un glibc 2.30 ... so use raw syscall - will work
@@ -1308,7 +1311,7 @@ eina_file_close_from(int fd, int *except
 #else
 #ifdef HAVE_DIRENT_H
 //# if 0
-# if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__linux__)
+# if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__linux__)
    int dirfd;
    Dirent *d;
    char buf[4096 + 128];

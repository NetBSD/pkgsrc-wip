$NetBSD$

* Add NetBSD support

--- src/lib/eina/eina_file.c.orig	2020-09-22 17:54:50.000000000 +0000
+++ src/lib/eina/eina_file.c
@@ -1297,6 +1297,16 @@ typedef struct
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
@@ -1320,7 +1330,7 @@ eina_file_close_from(int fd, int *except
 #else
 #ifdef HAVE_DIRENT_H
 //# if 0
-# if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__linux__)
+# if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__linux__)
    int dirfd;
    Dirent *d;
    char buf[4096];

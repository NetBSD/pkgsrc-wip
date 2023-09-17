$NetBSD$

Add NetBSD support.

--- hw/9pfs/9p-util.h.orig	2023-08-22 15:34:01.000000000 +0000
+++ hw/9pfs/9p-util.h
@@ -64,7 +64,7 @@ static inline uint64_t host_dev_to_dotl_
 static inline int errno_to_dotl(int err) {
 #if defined(CONFIG_LINUX)
     /* nothing to translate (Linux -> Linux) */
-#elif defined(CONFIG_DARWIN)
+#elif defined(CONFIG_DARWIN) || defined(CONFIG_BSD)
     /*
      * translation mandatory for macOS hosts
      *
@@ -154,13 +154,13 @@ static inline int openat_file(int dirfd,
 {
     int fd, serrno, ret;
 
-#ifndef CONFIG_DARWIN
+#ifdef CONFIG_LINUX
 again:
 #endif
     fd = qemu_openat(dirfd, name, flags | O_NOFOLLOW | O_NOCTTY | O_NONBLOCK,
                      mode);
     if (fd == -1) {
-#ifndef CONFIG_DARWIN
+#ifndef CONFIG_LINUX
         if (errno == EPERM && (flags & O_NOATIME)) {
             /*
              * The client passed O_NOATIME but we lack permissions to honor it.
@@ -213,6 +213,8 @@ static inline off_t qemu_dirent_off(stru
 {
 #ifdef CONFIG_DARWIN
     return dent->d_seekoff;
+#elif defined(CONFIG_BSD)
+    return 0; /* not supported */
 #else
     return dent->d_off;
 #endif

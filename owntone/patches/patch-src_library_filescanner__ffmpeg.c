$NetBSD$

--- src/library/filescanner_ffmpeg.c.orig	2025-07-08 21:13:46.878613539 +0000
+++ src/library/filescanner_ffmpeg.c
@@ -812,6 +812,25 @@ fast_copy(int fd_dst, int fd_src)
   // Here we use kernel-space copying for performance reasons
 #if defined(__APPLE__)
   return fcopyfile(fd_src, fd_dst, 0, COPYFILE_ALL);
+#elif defined(__NetBSD__)
+  while (true) {
+    unsigned char buf[1024/*?!?*/];
+    ssize_t nr;
+
+    nr = read(fd_src, buf, sizeof(buf));
+    if (nr == -1) {
+      return -1;
+    }
+
+    if (nr == 0) {
+      return 0;
+    }
+
+    if (write(fd_dst, buf, nr) != nr) {
+      return -1;
+    }
+
+  }
 #else
   struct stat fileinfo = { 0 };
   ssize_t bytes_copied;

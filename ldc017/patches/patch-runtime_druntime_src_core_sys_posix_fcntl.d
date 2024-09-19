$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/posix/fcntl.d.orig	2020-05-07 08:52:15.234684078 +0000
+++ runtime/druntime/src/core/sys/posix/fcntl.d
@@ -462,6 +462,59 @@ else version( DragonFlyBSD )
     //int fcntl(int, int, ...);  /*defined below*/
     //int flock(int, int);
 }
+else version( NetBSD )
+{
+    enum F_DUPFD        = 0;
+    enum F_GETFD        = 1;
+    enum F_SETFD        = 2;
+    enum F_GETFL        = 3;
+    enum F_SETFL        = 4;
+    enum F_GETOWN       = 5;
+    enum F_SETOWN       = 6;
+    enum F_GETLK        = 7;
+    enum F_SETLK        = 8;
+    enum F_SETLKW       = 9;
+    enum F_CLOSEM       = 10;
+    enum F_MAXFD        = 11;
+    enum F_DUPFD_CLOEXEC= 12;
+    enum F_GETNOSIGPIPE = 13;
+    enum F_SETNOSIGPIPE = 14;
+
+    enum FD_CLOEXEC     = 1;
+
+    enum F_RDLCK        = 1;
+    enum F_UNLCK        = 2;
+    enum F_WRLCK        = 3;
+
+    enum O_CREAT        = 0x0200;
+    enum O_EXCL         = 0x0800;
+    enum O_NOCTTY       = 0x8000;
+    enum O_TRUNC        = 0x0400;
+
+    enum O_RDONLY       = 0x0000;
+    enum O_WRONLY       = 0x0001;
+    enum O_RDWR         = 0x0002;
+    enum O_ACCMODE      = 0x0003;
+
+    enum O_NONBLOCK     = 0x0004;
+    enum O_APPEND       = 0x0008;
+    enum O_SYNC         = 0x0080;
+    //enum O_DSYNC
+    //enum O_RSYNC
+
+    struct flock
+    {
+        off_t   l_start;
+        off_t   l_len;
+        pid_t   l_pid;
+        short   l_type;
+        short   l_whence;
+    }
+
+
+    int creat(in char*, mode_t);
+    int open(in char*, int, ...);
+}
 else version (Solaris)
 {
     enum F_DUPFD = 0;

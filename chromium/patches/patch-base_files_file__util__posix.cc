$NetBSD$

--- base/files/file_util_posix.cc.orig	2020-06-25 09:31:18.000000000 +0000
+++ base/files/file_util_posix.cc
@@ -415,7 +415,7 @@ bool CreatePipe(ScopedFD* read_fd, Scope
 }
 
 bool CreateLocalNonBlockingPipe(int fds[2]) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return pipe2(fds, O_CLOEXEC | O_NONBLOCK) == 0;
 #else
   int raw_fds[2];

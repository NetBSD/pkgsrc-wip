$NetBSD: patch-src_java.base_unix_native_libjava_ProcessHandleImpl__unix.c,v 1.1 2019/10/01 12:36:34 tnn Exp $

waitid(2) is available in NetBSD>

--- src/java.base/unix/native/libjava/ProcessHandleImpl_unix.c.orig	2021-04-23 22:52:34.000000000 -0400
+++ src/java.base/unix/native/libjava/ProcessHandleImpl_unix.c	2021-06-10 13:33:38.712784156 -0400
@@ -252,7 +252,7 @@
             return status;
         }
      } else {
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
         return os_waitForProcessExitNoReap(pid);
 #else
         /*

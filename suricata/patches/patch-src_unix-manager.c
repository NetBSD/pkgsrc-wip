$NetBSD$

--- src/unix-manager.c.orig	2025-09-16 02:07:13.000000000 +0000
+++ src/unix-manager.c
@@ -186,7 +186,7 @@ static int UnixNew(UnixCommand * this)
         return 0;
     }
 
-#if !(defined OS_FREEBSD || defined __OpenBSD__)
+#if !(defined OS_FREEBSD || defined __OpenBSD__ || defined __NetBSD__)
     /* Set file mode: will not fully work on most system, the group
      * permission is not changed on some Linux. *BSD won't do the
      * chmod: it returns EINVAL when calling chmod on sockets. */

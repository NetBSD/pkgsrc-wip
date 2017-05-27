$NetBSD$

--- qemu-nbd.c.orig	2017-05-12 22:04:02.000000000 +0000
+++ qemu-nbd.c
@@ -283,8 +283,7 @@ static void *nbd_client_thread(void *arg
 
     fd = open(device, O_RDWR);
     if (fd < 0) {
-        /* Linux-only, we can use %m in printf.  */
-        error_report("Failed to open %s: %m", device);
+        error_report("Failed to open %s: %s", device, strerror(errno));
         goto out_socket;
     }
 

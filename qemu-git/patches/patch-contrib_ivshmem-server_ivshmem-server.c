$NetBSD$

--- contrib/ivshmem-server/ivshmem-server.c.orig	2017-04-25 12:42:53.000000000 +0000
+++ contrib/ivshmem-server/ivshmem-server.c
@@ -13,6 +13,10 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 
+    #include <sys/types.h>
+     #include <sys/mman.h>
+     #include <fcntl.h>
+
 #include "ivshmem-server.h"
 
 /* log a message on stdout if verbose=1 */

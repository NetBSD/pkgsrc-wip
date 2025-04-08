$NetBSD: patch-socket.c,v 1.4 2023/09/06 16:00:15 vins Exp $

Include <uio.h> for iovec. 

--- socket.c.orig	2017-07-10 19:26:25.000000000 +0000
+++ socket.c	2017-07-18 22:35:40.000000000 +0000
@@ -34,9 +34,7 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 # include <sys/socket.h>
-# ifdef _OpenBSD_
-#  include <sys/uio.h>
-# endif
+# include <sys/uio.h>
 # include <sys/un.h>
 
 #ifndef SIGINT

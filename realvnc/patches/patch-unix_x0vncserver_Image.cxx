$NetBSD: patch-unix_x0vncserver_Image.cxx,v 1.1 2012/11/12 14:32:14 thomasklausner Exp $

Another missing prototype.

--- unix/x0vncserver/Image.cxx.orig	2006-05-15 16:56:20.000000000 +0000
+++ unix/x0vncserver/Image.cxx
@@ -21,6 +21,7 @@
 
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/types.h>
 #include <sys/ipc.h>
 #include <sys/shm.h>

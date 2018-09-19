$NetBSD$

# Portability
--- gmetad/data_thread.c.orig	2015-07-01 19:49:35.000000000 +0000
+++ gmetad/data_thread.c
@@ -1,6 +1,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
+#ifndef __linux__
+#include <sys/filio.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/poll.h>
 #include <sys/time.h>

$NetBSD$

notify.c: In function 'sm_notify_rcv':
notify.c:170:17: error: storage size of 'timeout' isn't known
  struct timeval timeout;
                 ^~~~~~~
--- libsm/notify.c.orig	2017-02-17 03:44:29.000000000 +0900
+++ libsm/notify.c	2018-04-01 12:34:31.616373358 +0900
@@ -25,6 +25,8 @@
 #include <fcntl.h>
 #include <string.h>	/* for memset() */
 
+#include <sys/time.h>
+
 #if SM_NOTIFY_DEBUG
 #define SM_DBG(p)	fprintf p
 #else

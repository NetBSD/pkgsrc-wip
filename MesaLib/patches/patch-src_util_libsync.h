$NetBSD$

sys/ioccom.h for _IOWR

--- src/util/libsync.h.orig	2021-12-29 21:05:19.000000000 +0000
+++ src/util/libsync.h
@@ -34,6 +34,9 @@
 #include <stdint.h>
 #include <string.h>
 #include <sys/ioctl.h>
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
 #include <sys/poll.h>
 #include <unistd.h>
 

$NetBSD$

Add NetBSD support.

--- src/udscs.c.orig	2019-02-11 11:16:16.000000000 +0000
+++ src/udscs.c
@@ -34,6 +34,15 @@
 #include "udscs.h"
 #include "vdagentd-proto-strings.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#include <sys/ucred.h>
+#define ucred unpcbid
+#include <sys/un.h>
+#define SO_PEERCRED LOCAL_PEEREID
+#define pid unp_pid
+#endif
+
 struct udscs_buf {
     uint8_t *buf;
     size_t pos;

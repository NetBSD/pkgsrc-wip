$NetBSD$

# Hack to allow access to opaque structure members
--- src/common/callerid.c.orig	2016-05-03 22:41:59.000000000 +0000
+++ src/common/callerid.c
@@ -58,6 +58,14 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
+#endif
+
+/*
+ * FIXME: In in6.h, s6_addr32 def is guarded by #ifdef _KERNEL
+ * Is there a portable interface that could be used instead of accessing
+ * structure members directly?
+ */
+#if defined(__FreeBSD__) || defined(__NetBSD__)
 #define s6_addr32 __u6_addr.__u6_addr32
 #endif
 

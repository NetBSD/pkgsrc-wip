$NetBSD$

# Macros only provided for kernel in in6.h
--- src/common/callerid.c.orig	2016-05-03 22:41:59.000000000 +0000
+++ src/common/callerid.c
@@ -61,6 +61,12 @@
 #define s6_addr32 __u6_addr.__u6_addr32
 #endif
 
+#ifdef __NetBSD__
+#define s6_addr8  __u6_addr.__u6_addr8
+#define s6_addr16 __u6_addr.__u6_addr16
+#define s6_addr32 __u6_addr.__u6_addr32
+#endif
+
 #if HAVE_DIRENT_H
 #  include <dirent.h>
 #endif

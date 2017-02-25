$NetBSD$

--- src/plugin_netbsd.h.orig	2017-02-25 13:40:51.439972628 +0000
+++ src/plugin_netbsd.h
@@ -0,0 +1,14 @@
+#ifndef NETDATA_PLUGIN_NETBSD_H
+#define NETDATA_PLUGIN_NETBSD_H 1
+
+#include <sys/sysctl.h>
+
+#define GETSYSCTL(name, var) getsysctl(name, &(var), sizeof(var))
+
+void *netbsd_main(void *ptr);
+
+int getsysctl(const char *name, void *ptr, size_t len);
+
+extern int do_netbsd_sysctl(int update_every, usec_t dt);
+
+#endif /* NETDATA_PLUGIN_NETBSD_H */

$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/netbsd/sys/cdefs.d.orig	2016-03-02 01:38:47.237364846 +0000
+++ runtime/druntime/src/core/sys/netbsd/sys/cdefs.d
@@ -0,0 +1,16 @@
+/**
+ * D header file for FreeBSD
+ *
+ * Authors: Martin Nowak
+ */
+module core.sys.netbsd.sys.cdefs;
+
+version (NetBSD):
+
+public import core.sys.posix.config;
+
+
+enum __POSIX_VISIBLE = 200112;
+enum __XSI_VISIBLE = 700;
+enum __BSD_VISIBLE = true;
+enum __ISO_C_VISIBLE = 1999;

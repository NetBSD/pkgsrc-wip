$NetBSD$

Stolen from https://github.com/nrTQgc/druntime/tree/netbsd

--- runtime/druntime/src/core/sys/netbsd/sys/elf.d.orig	2016-03-02 01:38:47.238980833 +0000
+++ runtime/druntime/src/core/sys/netbsd/sys/elf.d
@@ -0,0 +1,11 @@
+/**
+ * D header file for NetBSD.
+ *
+ * $(LINK2 http://svnweb.freebsd.org/base/head/sys/sys/elf.h?view=markup, sys/elf.h)
+ */
+module core.sys.netbsd.sys.elf;
+
+version (NetBSD):
+
+public import core.sys.netbsd.sys.elf32;
+public import core.sys.netbsd.sys.elf64;

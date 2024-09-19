$NetBSD$

--- src/arch/netbsd/async/debug.h.orig	2017-11-02 06:34:33.814576267 +0000
+++ src/arch/netbsd/async/debug.h
@@ -0,0 +1,6 @@
+#ifndef __DEBUG_H
+#define __DEBUG_H
+
+void gdb_debug(void);
+
+#endif

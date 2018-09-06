$NetBSD$

--- src/x86_64/Los-netbsd.c.orig	2018-09-05 10:31:53.522195751 +0000
+++ src/x86_64/Los-netbsd.c
@@ -0,0 +1,5 @@
+#define UNW_LOCAL_ONLY
+#include <libunwind.h>
+#if defined(UNW_LOCAL_ONLY) && !defined(UNW_REMOTE_ONLY)
+#include "Gos-netbsd.c"
+#endif

$NetBSD$

--- util-src/signal.c.orig	2017-11-17 20:50:20.874396000 +0000
+++ util-src/signal.c
@@ -31,6 +31,10 @@
 #include <signal.h>
 #include <stdlib.h>
 
+#ifdef __unix__
+#include <sys/param.h>
+#endif
+
 #include "lua.h"
 #include "lauxlib.h"
 

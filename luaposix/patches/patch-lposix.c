$NetBSD: patch-lposix.c,v 1.1 2013/02/22 09:46:32 jonperkin Exp $

Avoid conflict with SunOS NODEV definition.

--- lposix.c.orig	2012-10-03 20:05:24.000000000 +0000
+++ lposix.c
@@ -56,6 +56,9 @@
 #include "lauxlib.h"
 #include "lua52compat.h"
 
+#ifdef __sun
+#undef NODEV
+#endif
 
 /* The extra indirection to these macros is required so that if the
    arguments are themselves macros, they will get expanded too.  */

$NetBSD$

Need sys/cdefs.h for __BEGIN_DECLS/__END_DECLS.

--- bin/varnishd/cache/cache_panic.c.orig	2017-03-14 14:44:51.000000000 +0000
+++ bin/varnishd/cache/cache_panic.c
@@ -29,6 +29,10 @@
 
 #include "config.h"
 
+#ifdef __NetBSD__
+#include <sys/cdefs.h>
+#endif
+
 #include <execinfo.h>
 #include <errno.h>
 #include <stdio.h>

$NetBSD: patch-src_topology_tplg__local.h,v 1.1 2016/02/18 15:15:57 wiz Exp $

--- src/topology/tplg_local.h.orig	2016-02-24 08:33:29.000000000 +0000
+++ src/topology/tplg_local.h
@@ -13,8 +13,10 @@
 #include <limits.h>
 #include <stdint.h>
 #include <stdbool.h>
+#ifdef __linux__
 #include <endian.h>
 #include <linux/types.h>
+#endif
 
 #include "local.h"
 #include "list.h"

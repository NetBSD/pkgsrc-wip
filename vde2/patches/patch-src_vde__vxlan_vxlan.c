$NetBSD$

Required header.

--- src/vde_vxlan/vxlan.c.orig	2026-08-03 10:48:09.000000000 +0000
+++ src/vde_vxlan/vxlan.c
@@ -24,6 +24,7 @@
 
 #include <netinet/in.h>
 #include <sys/un.h>
+#include <sys/socket.h>
 
 #include "vxlan_hash.h"
 #include "log.h"

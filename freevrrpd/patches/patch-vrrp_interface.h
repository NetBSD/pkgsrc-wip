$NetBSD$

Remove duplicate #include

--- vrrp_interface.h.orig	2015-02-04 00:39:49.000000000 +0000
+++ vrrp_interface.h
@@ -53,7 +53,6 @@
 #include <unistd.h>
 #include <stdarg.h>
 #include <net/if.h>
-#include <net/ethernet.h>
 #include <net/if_bridgevar.h>
 #include "vrrp_define.h"
 #include "vrrp_proto.h"

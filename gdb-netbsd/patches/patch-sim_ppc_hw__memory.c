$NetBSD$

--- sim/ppc/hw_memory.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ sim/ppc/hw_memory.c
@@ -29,6 +29,8 @@
 
 #include "device_table.h"
 
+#include <stdlib.h>
+
 /* DEVICE
 
 

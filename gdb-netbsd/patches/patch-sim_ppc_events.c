$NetBSD$

--- sim/ppc/events.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ sim/ppc/events.c
@@ -24,6 +24,7 @@
 #include "basics.h"
 #include "events.h"
 
+#include <stdlib.h>
 #include <signal.h>
 #include <stdlib.h>
 

$NetBSD$

--- gdb/sparc64-nbsd-tdep.c.orig	2019-07-16 00:00:27.000000000 +0000
+++ gdb/sparc64-nbsd-tdep.c
@@ -31,6 +31,7 @@
 #include "trad-frame.h"
 
 #include "sparc64-tdep.h"
+#include "sparc-nbsd-tdep.h"
 #include "nbsd-tdep.h"
 
 /* From <machine/reg.h>.  */

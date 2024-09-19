$NetBSD$

--- hald/freebsd/hf-storage.c.orig	2009-08-24 12:42:29.000000000 +0000
+++ hald/freebsd/hf-storage.c
@@ -33,6 +33,9 @@
 #include <sys/param.h>
 #include <sys/types.h>
 #include <sys/disklabel.h>
+#ifdef __DragonFly__
+#include <sys/dtype.h>
+#endif
 
 #include "../logger.h"
 #include "../osspec.h"

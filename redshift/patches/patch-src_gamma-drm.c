$NetBSD$

alloca is in #include <stdlib.h>
--- src/gamma-drm.c.orig	2016-01-02 23:09:13.000000000 +0000
+++ src/gamma-drm.c
@@ -21,7 +21,6 @@
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>
-#include <alloca.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>

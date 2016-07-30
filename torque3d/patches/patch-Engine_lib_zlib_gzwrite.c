$NetBSD$

--- Engine/lib/zlib/gzwrite.c.orig	2016-07-12 13:56:01.000000000 +0000
+++ Engine/lib/zlib/gzwrite.c
@@ -5,6 +5,8 @@
 
 #include "gzguts.h"
 
+#include <unistd.h>
+
 /* Local functions */
 local int gz_init OF((gz_statep));
 local int gz_comp OF((gz_statep, int));

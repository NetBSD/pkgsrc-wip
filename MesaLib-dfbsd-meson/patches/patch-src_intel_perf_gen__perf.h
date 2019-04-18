$NetBSD$

--- src/intel/perf/gen_perf.h.orig	2019-04-17 15:42:13.000000000 +0000
+++ src/intel/perf/gen_perf.h
@@ -28,7 +28,9 @@
 #include <stdint.h>
 #include <string.h>
 
+#ifdef MAJOR_IN_SYSMACROS
 #include <sys/sysmacros.h>
+#endif
 
 #include "util/hash_table.h"
 #include "util/ralloc.h"

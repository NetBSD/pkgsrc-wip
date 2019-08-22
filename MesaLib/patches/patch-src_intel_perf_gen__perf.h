$NetBSD$

for major() - sysmacros.h is non-portable

--- src/intel/perf/gen_perf.h.orig	2019-08-07 16:39:17.000000000 +0000
+++ src/intel/perf/gen_perf.h
@@ -28,7 +28,9 @@
 #include <stdint.h>
 #include <string.h>
 
+#ifdef __linux
 #include <sys/sysmacros.h>
+#endif
 
 #include "util/hash_table.h"
 #include "util/ralloc.h"

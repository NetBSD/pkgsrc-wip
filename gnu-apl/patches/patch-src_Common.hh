$NetBSD$

SunOS fix: Add alloca.h which is needed

--- src/Common.hh.orig
+++ src/Common.hh
@@ -50,6 +50,9 @@
 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
+#if defined(__sun)
+#include <alloca.h>
+#endif
 #include <sys/time.h>   // for gettimeofday()
 
 #ifndef RLIM_INFINITY   // Raspberry

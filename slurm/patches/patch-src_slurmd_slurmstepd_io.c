$NetBSD$

--- src/slurmd/slurmstepd/io.c.orig	2018-01-05 23:43:03.000000000 +0000
+++ src/slurmd/slurmstepd/io.c
@@ -45,6 +45,7 @@
 #endif
 
 #ifdef HAVE_UTMP_H
+#  include <time.h>
 #  include <utmp.h>
 #endif
 

$NetBSD$

# Fix missing constants

--- ompi/mca/sharedfp/sm/sharedfp_sm.c.orig	2022-07-29 23:04:14.067867314 +0000
+++ ompi/mca/sharedfp/sm/sharedfp_sm.c
@@ -26,6 +26,7 @@
  * modules just to query their version and parameters
  */
 
+#include <sys/stat.h>	// Hack for NetBSD
 #include "ompi_config.h"
 #include "mpi.h"
 #include "ompi/mca/sharedfp/sharedfp.h"

$NetBSD: patch-include_gn_gnDefs.h,v 1.1 2012/11/03 16:00:28 outpaddling Exp $

--- include/gn/gnDefs.h.orig	2003-05-01 08:24:50.000000000 +0000
+++ include/gn/gnDefs.h
@@ -17,6 +17,7 @@
 
 #include <limits.h>
 #include <float.h>
+#include <string.h>	// pkgsrc on RHEL/CentOS needs this
 #include "gn/gnSetup.h"
 
 // bool	

$NetBSD: patch-lib_tt_bin_dbck_options.C,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- lib/tt/bin/dbck/options.C.orig	2012-09-28 20:48:33.000000000 +0000
+++ lib/tt/bin/dbck/options.C
@@ -37,7 +37,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include "util/copyright.h"
-#if defined(linux) || defined(sgi) || defined(__FreeBSD__)
+#if defined(linux) || defined(sgi) || defined(CSRG_BASED)
 #include <getopt.h>
 #endif     
 #include "dbck.h"     

$NetBSD: patch-src_libs3decoder_libsearch_fsg__history.c,v 1.1 2013/09/24 11:13:53 fhajny Exp $

Only use libbsd on Linux.
--- src/libs3decoder/libsearch/fsg_history.c.orig	2008-12-31 18:27:56.000000000 +0000
+++ src/libs3decoder/libsearch/fsg_history.c
@@ -55,7 +55,9 @@
 #include <kb.h>
 /*#include <phone.h>*/
 #include <search.h>
+#if defined(__linux__)
 #include "libutil.h"
+#endif
 
 
 #define __FSG_DBG__	0

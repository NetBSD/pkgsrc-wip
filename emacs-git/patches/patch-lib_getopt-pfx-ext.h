$NetBSD$

getopt warning fix, from upstream.

--- lib/getopt-pfx-ext.h.orig	2026-07-14 17:23:34.000000000 +0000
+++ lib/getopt-pfx-ext.h
@@ -58,6 +58,7 @@
 #ifndef __getopt_argv_const
 # if defined __GETOPT_PREFIX
 #  define __getopt_argv_const /* empty */
+#  define __getopt_argv_const_is_empty 1
 # else
 #  define __getopt_argv_const const
 # endif

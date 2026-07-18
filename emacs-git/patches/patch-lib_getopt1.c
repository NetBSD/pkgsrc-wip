$NetBSD$

getopt warning fix, from upstream.

--- lib/getopt1.c.orig	2026-07-14 17:23:34.000000000 +0000
+++ lib/getopt1.c
@@ -24,11 +24,19 @@
 #include <getopt.h>
 #include "getopt_int.h"
 
+/* Convert char *__getopt_argv_const * to char ** without provoking
+   gcc -Wuseless-cast when __getopt_argv_const is empty.  */
+#ifdef __getopt_argv_const_is_empty
+# define ARGV_CAST(argv) (argv)
+#else
+# define ARGV_CAST(argv) ((char **) (argv))
+#endif
+
 int
 getopt_long (int argc, char *__getopt_argv_const *argv, const char *options,
 	     const struct option *long_options, int *opt_index)
 {
-  return _getopt_internal (argc, (char **) argv, options, long_options,
+  return _getopt_internal (argc, ARGV_CAST (argv), options, long_options,
 			   opt_index, 0, 0);
 }
 
@@ -51,7 +59,7 @@ getopt_long_only (int argc, char *__getopt_argv_const 
 		  const char *options,
 		  const struct option *long_options, int *opt_index)
 {
-  return _getopt_internal (argc, (char **) argv, options, long_options,
+  return _getopt_internal (argc, ARGV_CAST (argv), options, long_options,
 			   opt_index, 1, 0);
 }
 

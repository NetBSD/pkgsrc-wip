$NetBSD$

Fix getopt1.c:31:34: warning: useless cast to type 'char **' [-Wuseless-cast]
From upstream.

--- lib/getopt1.c.orig	2026-07-14 17:23:34.000000000 +0000
+++ lib/getopt1.c
@@ -28,7 +28,7 @@ getopt_long (int argc, char *__getopt_argv_const *argv
 getopt_long (int argc, char *__getopt_argv_const *argv, const char *options,
 	     const struct option *long_options, int *opt_index)
 {
-  return _getopt_internal (argc, (char **) argv, options, long_options,
+  return _getopt_internal (argc, (char **) { argv }, options, long_options,
 			   opt_index, 0, 0);
 }
 
@@ -51,7 +51,7 @@ getopt_long_only (int argc, char *__getopt_argv_const 
 		  const char *options,
 		  const struct option *long_options, int *opt_index)
 {
-  return _getopt_internal (argc, (char **) argv, options, long_options,
+  return _getopt_internal (argc, (char **) { argv }, options, long_options,
 			   opt_index, 1, 0);
 }
 

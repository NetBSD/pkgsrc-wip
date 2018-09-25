$NetBSD$

Use getopt() from gnulib.

--- src/builtins.c.orig	2011-02-11 16:32:57.000000000 +0000
+++ src/builtins.c
@@ -20,6 +20,10 @@
  * posh built-in commands: posh_builtin_*
  */
 
+/* For getopt() from gnulib */
+#include "config.h"
+#include <getopt.h>
+
 #include "sh.h"
 #include "ksh_stat.h"
 #include <ctype.h>

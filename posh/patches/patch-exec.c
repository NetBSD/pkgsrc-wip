$NetBSD$

Use getopt() from gnulib.

--- exec.c.orig	2013-05-31 01:14:12.000000000 +0000
+++ exec.c
@@ -2,6 +2,10 @@
  * execute command tree
  */
 
+/* For getopt() from gnulib */
+#include "config.h"
+#include <getopt.h>
+
 #include "sh.h"
 #include "c_test.h"
 #include <ctype.h>

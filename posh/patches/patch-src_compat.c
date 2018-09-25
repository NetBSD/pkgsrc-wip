$NetBSD$

Include config.h first for gnulib.

--- src/compat.c.orig	2009-10-20 19:40:36.000000000 +0000
+++ src/compat.c
@@ -1,3 +1,5 @@
+#include "config.h"
+
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
@@ -5,8 +7,6 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
-#include "config.h"
-
 /* The following function, get_current_dir_name, has been adapted from the
    GNU C Library.
 

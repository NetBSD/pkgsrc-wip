$NetBSD: patch-input_bdecode.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for exit(3).

--- input/bdecode.c.orig	1991-11-04 18:18:39.000000000 +0000
+++ input/bdecode.c
@@ -2,6 +2,7 @@
  * bdecode [file]
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include "coder.h"
 char *myname, *inputfile = "(stdin)";

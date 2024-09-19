$NetBSD: patch-batch_batcher.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for exit(3).

--- batch/batcher.c.orig	1994-11-28 01:14:35.000000000 +0000
+++ batch/batcher.c
@@ -12,6 +12,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <signal.h>
 #include <sys/types.h>

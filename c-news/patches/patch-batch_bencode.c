$NetBSD: patch-batch_bencode.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for exit(3).

--- batch/bencode.c.orig	1991-11-04 18:16:50.000000000 +0000
+++ batch/bencode.c
@@ -2,6 +2,7 @@
  * bencode [file]
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include "coder.h"
 #define MAXPERLINE 78		/* max chars/line */
 char *myname;

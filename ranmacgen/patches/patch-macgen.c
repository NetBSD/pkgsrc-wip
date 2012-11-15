$NetBSD: patch-macgen.c,v 1.1 2012/11/15 20:20:56 othyro Exp $

Fixes "reference to compatibility time();" warning.

--- macgen.c.orig	2005-10-24 19:53:46.000000000 +0000
+++ macgen.c
@@ -8,6 +8,7 @@
    */
 #include <stdio.h>
 #include <stdlib.h>
+#include <time.h>
 
 
     main () {

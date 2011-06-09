$NetBSD: patch-inject_defaults.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for exit(3).

--- inject/defaults.c.orig	1995-01-02 21:48:38.000000000 +0000
+++ inject/defaults.c
@@ -3,6 +3,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include <pwd.h>

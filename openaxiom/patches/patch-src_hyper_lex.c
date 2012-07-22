$NetBSD: patch-src_hyper_lex.c,v 1.1 2012/07/22 16:43:58 asau Exp $

--- src/hyper/lex.c.orig	2012-07-21 20:25:34.000000000 +0000
+++ src/hyper/lex.c
@@ -62,6 +62,7 @@
 #include <ctype.h>
 #include <setjmp.h>
 #include <stdlib.h>
+#include <string.h>
 
 #include "debug.h"
 #include "sockio.h"

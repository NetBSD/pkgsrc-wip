$NetBSD: patch-src_hyper_htadd.c,v 1.1 2012/07/22 16:43:58 asau Exp $

--- src/hyper/htadd.c.orig	2012-07-21 20:25:34.000000000 +0000
+++ src/hyper/htadd.c
@@ -43,6 +43,7 @@
 #include <stdlib.h>
 #include <sys/stat.h>
 #include <stdlib.h>
+#include <string.h>
 #include <locale.h>
 
 #include "cfuns.h"

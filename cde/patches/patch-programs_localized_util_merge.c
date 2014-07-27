$NetBSD: patch-programs_localized_util_merge.c,v 1.1 2014/07/27 07:44:56 obache Exp $

* require prototypes for str* functions.

--- programs/localized/util/merge.c.orig	2014-03-01 22:48:49.000000000 +0000
+++ programs/localized/util/merge.c
@@ -95,6 +95,7 @@
 #include <stdlib.h>
 #include <locale.h>
 #include <nl_types.h>
+#include <string.h>
 
 nl_catd catfile[2] = {NULL, NULL};	/* [0] for primary, [1] for default */
 char *big_buff;

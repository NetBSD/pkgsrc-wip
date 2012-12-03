$NetBSD: patch-mft_log.c,v 1.1 2012/12/03 13:50:15 othyro Exp $

Needs sys_errlist.

--- mft/log.c.orig	2000-03-09 05:36:50.000000000 +0000
+++ mft/log.c
@@ -22,6 +22,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdarg.h>
+#include <errno.h>
 #include <string.h>
 #include <malloc.h>
 #include <unistd.h>

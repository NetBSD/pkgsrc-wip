$NetBSD: patch-libc_fgetfln.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for str*(3).

--- libc/fgetfln.c.orig	1993-03-09 06:22:54.000000000 +0000
+++ libc/fgetfln.c
@@ -5,6 +5,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <ctype.h>
 #include <sys/types.h>
 #include <fgetfln.h>

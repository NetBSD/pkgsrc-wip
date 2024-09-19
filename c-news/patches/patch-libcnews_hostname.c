$NetBSD: patch-libcnews_hostname.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for str*(3).

--- libcnews/hostname.c.orig	1993-11-21 02:24:17.000000000 +0000
+++ libcnews/hostname.c
@@ -7,6 +7,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #include <sys/types.h>
 
 #include "libc.h"

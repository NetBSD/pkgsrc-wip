$NetBSD: patch-drow.c,v 1.1 2012/12/03 23:58:09 othyro Exp $

Fix implicit declaration of exit.

--- drow.c.orig	2003-08-21 21:30:12.000000000 +0000
+++ drow.c
@@ -26,6 +26,7 @@ Foundation, Inc., 59 Temple Place - Suit
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>

$NetBSD: patch-input_c7decode.c,v 1.1 2011/06/09 16:22:57 hfath Exp $

Prototype for exit(3).

--- input/c7decode.c.orig	1989-02-21 22:57:32.000000000 +0000
+++ input/c7decode.c
@@ -1,4 +1,5 @@
 #include <stdio.h>
+#include <stdlib.h>
 
 /*
  * This program is the inverse of encode

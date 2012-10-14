$NetBSD: patch-readseq.c,v 1.1 2012/10/14 18:12:13 asau Exp $

Pull stdlib.h for malloc.

--- readseq.c.orig	1993-01-12 12:43:06.000000000 +0000
+++ readseq.c
@@ -161,6 +161,7 @@ link -w -o readseq -t MPST -c 'MPS ' ¶
 
 
 
+#include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>

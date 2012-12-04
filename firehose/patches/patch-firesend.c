$NetBSD: patch-firesend.c,v 1.1 2012/12/04 01:29:39 othyro Exp $

Needs strcpy and strlen.

--- firesend.c.orig	2003-10-14 07:54:07.000000000 +0000
+++ firesend.c
@@ -1,6 +1,7 @@
 #include "firehose.h"
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <sys/time.h>
 
 #define BUFFER_SIZE 0x100000

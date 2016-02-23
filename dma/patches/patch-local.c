$NetBSD$

Include strings.h for bzero and bcopy function.

--- local.c.orig	2016-02-07 12:41:49.000000000 +0000
+++ local.c
@@ -45,6 +45,7 @@
 #include <stdint.h>
 #include <stdio.h>
 #include <syslog.h>
+#include <strings.h>
 #include <unistd.h>
 
 #include "dma.h"

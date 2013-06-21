$NetBSD: patch-libf95.a-0.92_io_atof.c,v 1.1 2013/06/21 07:38:53 makoto Exp $

Needs stdlib.h on netbsd to get alloca() declaration.

--- libf95.a-0.93/io/atof.c~	2009-04-22 17:44:56.000000000 +0000
+++ libf95.a-0.93/io/atof.c
@@ -2,6 +2,7 @@
 
 
 
+#include <stdlib.h>
 #include <string.h>
 #include "runtime.h"
 

$NetBSD$

Inlcude missing system header file.

--- getdate.y.orig	2008-11-28 19:42:06.000000000 +0000
+++ getdate.y
@@ -58,6 +58,7 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <time.h>
+#include <stdlib.h>
 
 #include "config.h"
 #include "utils.h"

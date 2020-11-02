$NetBSD$

avoid platform whitelist

--- Source/Lib/Codec/EbUtility.c.orig	2020-10-30 01:51:10.000000000 +0000
+++ Source/Lib/Codec/EbUtility.c
@@ -13,7 +13,7 @@
 #include <stdio.h>
 
 //#endif
-#elif __linux__
+#else
 #include <stdio.h>
 #include <stdlib.h>
 #include "EbDefinitions.h"
@@ -22,8 +22,6 @@
 #include <time.h>
 //#endif
 
-#else
-#error OS/Platform not supported.
 #endif
 
 static PaBlockStats pa_get_block_stats_array[] = {

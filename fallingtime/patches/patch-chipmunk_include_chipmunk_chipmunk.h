$NetBSD$
--- ./chipmunk/include/chipmunk/chipmunk.h.orig	2016-01-23 21:07:04.000000000 -0800
+++ ./chipmunk/include/chipmunk/chipmunk.h	2016-01-23 21:07:09.000000000 -0800 
@@ -33,7 +33,9 @@
 	// For alloca().
 	#include <malloc.h>
 #else
-	#include <alloca.h>
+	#if HAVE_ALLOCA_H
+		#include <alloca.h>
+	#endif
 #endif
 
 #ifdef __cplusplus

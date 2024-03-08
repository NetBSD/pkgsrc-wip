$NetBSD: patch-gcc_system.h,v 1.1 2019/09/20 15:20:20 bouyer Exp $

--- gcc/system.h.orig	2015-01-05 12:33:28.000000000 +0000
+++ gcc/system.h
@@ -44,6 +44,9 @@ along with GCC; see the file COPYING3.  
 #endif
 
 #include <stdio.h>
+#ifdef __cplusplus
+# include <cstdio>
+#endif
 
 /* Define a generic NULL if one hasn't already been defined.  */
 #ifndef NULL

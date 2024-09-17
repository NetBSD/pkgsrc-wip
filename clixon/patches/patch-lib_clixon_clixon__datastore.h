$NetBSD$

Add include file to bring "struct timeval" in scope.

--- lib/clixon/clixon_datastore.h.orig	2024-09-17 11:49:43.889641347 +0000
+++ lib/clixon/clixon_datastore.h
@@ -38,6 +38,8 @@
 #ifndef _CLIXON_DATASTORE_H
 #define _CLIXON_DATASTORE_H
 
+#include <sys/time.h>	/* struct timeval */
+
 /*
  * Types
  */

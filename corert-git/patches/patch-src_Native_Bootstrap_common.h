$NetBSD$

--- src/Native/Bootstrap/common.h.orig	2016-01-23 11:26:49.000000000 +0000
+++ src/Native/Bootstrap/common.h
@@ -23,8 +23,10 @@
 
 #ifndef WIN32
 #include <pthread.h>
+#if HAVE_ALLOCA_H
 #include <alloca.h>
 #endif
+#endif
 
 using namespace std;
 

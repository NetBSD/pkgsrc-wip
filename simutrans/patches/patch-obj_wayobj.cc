$NetBSD$

--- obj/wayobj.cc.orig	2015-01-24 20:36:34.000000000 +0000
+++ obj/wayobj.cc
@@ -43,7 +43,7 @@
 
 #ifdef MULTI_THREAD
 #include "../utils/simthread.h"
-static pthread_mutex_t wayobj_calc_bild_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+static pthread_mutex_t wayobj_calc_bild_mutex = PTHREAD_MUTEX_INITIALIZER;
 #endif
 
 // the descriptions ...

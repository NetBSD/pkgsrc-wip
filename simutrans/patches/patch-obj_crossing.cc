$NetBSD$

--- obj/crossing.cc.orig	2015-08-30 18:18:58.000000000 +0000
+++ obj/crossing.cc
@@ -26,7 +26,7 @@
 
 #ifdef MULTI_THREAD
 #include "../utils/simthread.h"
-static pthread_mutex_t crossing_logic_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+static pthread_mutex_t crossing_logic_mutex = PTHREAD_MUTEX_INITIALIZER;
 #endif
 
 

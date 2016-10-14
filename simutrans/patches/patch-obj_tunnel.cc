$NetBSD$

--- obj/tunnel.cc.orig	2015-01-24 20:36:34.000000000 +0000
+++ obj/tunnel.cc
@@ -26,7 +26,7 @@
 
 #ifdef MULTI_THREAD
 #include "../utils/simthread.h"
-static pthread_mutex_t tunnel_calc_bild_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+static pthread_mutex_t tunnel_calc_bild_mutex = PTHREAD_MUTEX_INITIALIZER;
 #endif
 
 

$NetBSD$

--- boden/wege/weg.cc.orig	2015-11-29 19:41:00.000000000 +0000
+++ boden/wege/weg.cc
@@ -46,7 +46,7 @@
 
 #ifdef MULTI_THREAD
 #include "../../utils/simthread.h"
-static pthread_mutex_t weg_calc_bild_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+static pthread_mutex_t weg_calc_bild_mutex = PTHREAD_MUTEX_INITIALIZER;
 #endif
 
 /**

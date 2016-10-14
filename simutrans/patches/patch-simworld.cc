$NetBSD$

--- simworld.cc.orig	2016-01-25 20:42:10.000000000 +0000
+++ simworld.cc
@@ -5483,7 +5483,7 @@ DBG_MESSAGE("karte_t::laden()","Savegame
 
 
 #ifdef MULTI_THREAD
-static pthread_mutex_t height_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+static pthread_mutex_t height_mutex = PTHREAD_MUTEX_INITIALIZER;
 #endif
 
 

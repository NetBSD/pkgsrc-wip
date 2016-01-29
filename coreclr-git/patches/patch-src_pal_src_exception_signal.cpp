$NetBSD$

--- src/pal/src/exception/signal.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/pal/src/exception/signal.cpp
@@ -45,7 +45,7 @@ using namespace CorUnix;
 
 SET_DEFAULT_DEBUG_CHANNEL(EXCEPT);
 
-#define INJECT_ACTIVATION_SIGNAL SIGRTMIN
+#define INJECT_ACTIVATION_SIGNAL 0
 
 /* local type definitions *****************************************************/
 

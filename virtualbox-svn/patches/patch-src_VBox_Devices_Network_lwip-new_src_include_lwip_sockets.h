$NetBSD$

--- src/VBox/Devices/Network/lwip-new/src/include/lwip/sockets.h.orig	2016-08-05 16:20:22.000000000 +0000
+++ src/VBox/Devices/Network/lwip-new/src/include/lwip/sockets.h
@@ -361,9 +361,11 @@ typedef struct ip_mreq {
 /** LWIP_TIMEVAL_PRIVATE: if you want to use the struct timeval provided
  * by your system, set this to 0 and include <sys/time.h> in cc.h */ 
 #ifndef LWIP_TIMEVAL_PRIVATE
-#define LWIP_TIMEVAL_PRIVATE 1
+#define LWIP_TIMEVAL_PRIVATE 0
 #endif
 
+#include <sys/time.h>
+
 #if LWIP_TIMEVAL_PRIVATE
 struct timeval {
   long    tv_sec;         /* seconds */

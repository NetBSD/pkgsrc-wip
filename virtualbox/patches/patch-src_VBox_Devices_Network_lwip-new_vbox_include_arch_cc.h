$NetBSD$

--- src/VBox/Devices/Network/lwip-new/vbox/include/arch/cc.h.orig	2018-12-18 12:58:36.000000000 +0000
+++ src/VBox/Devices/Network/lwip-new/vbox/include/arch/cc.h
@@ -12,6 +12,7 @@
 
 #ifndef RT_OS_WINDOWS
 # define LWIP_TIMEVAL_PRIVATE 0
+# include <sys/time.h>
 #endif
 
 typedef uint8_t u8_t;

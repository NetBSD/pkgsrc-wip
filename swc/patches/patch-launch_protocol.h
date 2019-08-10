$NetBSD$

--- launch/protocol.h.orig	2019-07-11 06:33:41.000000000 +0000
+++ launch/protocol.h
@@ -24,9 +24,10 @@
 #ifndef SWC_LAUNCH_PROTOCOL_H
 #define SWC_LAUNCH_PROTOCOL_H
 
+#include <sys/types.h>
+#include <sys/uio.h>
 #include <stdbool.h>
 #include <stdint.h>
-#include <sys/types.h>
 
 #define SWC_LAUNCH_SOCKET_ENV "SWC_LAUNCH_SOCKET"
 

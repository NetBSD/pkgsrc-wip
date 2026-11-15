$NetBSD$

* Import from chromium

--- src/webrtc/src/rtc_base/physical_socket_server.h.orig	2026-09-29 23:13:58.000000000 +0000
+++ src/webrtc/src/rtc_base/physical_socket_server.h
@@ -22,7 +22,7 @@
 #include "rtc_base/socket_address.h"
 
 #if defined(WEBRTC_POSIX)
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) && !defined(WEBRTC_BSD)
 // On Linux, use epoll.
 #include <sys/epoll.h>
 

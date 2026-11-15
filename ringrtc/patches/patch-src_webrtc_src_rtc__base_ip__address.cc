$NetBSD$

* Import from chromium

--- src/webrtc/src/rtc_base/ip_address.cc.orig	2026-09-29 23:13:58.000000000 +0000
+++ src/webrtc/src/rtc_base/ip_address.cc
@@ -22,7 +22,8 @@
 #include "rtc_base/string_utils.h"
 
 #if defined(WEBRTC_POSIX)
-#ifdef OPENBSD
+#if defined(WEBRTC_BSD)
+#include <sys/types.h>
 #include <netinet/in_systm.h>
 #endif
 #include <netdb.h>

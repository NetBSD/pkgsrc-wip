$NetBSD$

--- device/media_transfer_protocol/media_transfer_protocol_daemon_client.h.orig	2017-02-02 02:02:54.000000000 +0000
+++ device/media_transfer_protocol/media_transfer_protocol_daemon_client.h
@@ -19,7 +19,7 @@
 #include "base/macros.h"
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 #error "Only used on Linux and ChromeOS"
 #endif
 

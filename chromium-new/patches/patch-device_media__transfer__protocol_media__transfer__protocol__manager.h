$NetBSD$

--- device/media_transfer_protocol/media_transfer_protocol_manager.h.orig	2016-11-10 20:02:14.000000000 +0000
+++ device/media_transfer_protocol/media_transfer_protocol_manager.h
@@ -15,7 +15,7 @@
 #include "base/memory/ref_counted.h"
 #include "build/build_config.h"
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_FREEBSD)
 #error "Only used on Linux and ChromeOS"
 #endif
 

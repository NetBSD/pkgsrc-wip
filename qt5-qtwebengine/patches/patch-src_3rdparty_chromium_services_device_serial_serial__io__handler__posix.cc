$NetBSD$

--- src/3rdparty/chromium/services/device/serial/serial_io_handler_posix.cc.orig	2020-07-15 18:56:01.000000000 +0000
+++ src/3rdparty/chromium/services/device/serial/serial_io_handler_posix.cc
@@ -66,7 +66,7 @@ bool BitrateToSpeedConstant(int bitrate,
     BITRATE_TO_SPEED_CASE(9600)
     BITRATE_TO_SPEED_CASE(19200)
     BITRATE_TO_SPEED_CASE(38400)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     BITRATE_TO_SPEED_CASE(57600)
     BITRATE_TO_SPEED_CASE(115200)
     BITRATE_TO_SPEED_CASE(230400)

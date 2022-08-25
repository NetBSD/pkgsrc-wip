$NetBSD$

Treat NetBSD the same as OpenBSD.

--- src/slic3r/Utils/Serial.cpp.orig	2022-03-10 10:35:03.000000000 +0000
+++ src/slic3r/Utils/Serial.cpp
@@ -49,7 +49,7 @@
 	#include <sys/select.h>
 #endif
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
 	#include <termios.h>
 #elif defined __linux__
 	#include <fcntl.h>
@@ -342,7 +342,7 @@ void Serial::set_baud_rate(unsigned baud
 		ios.c_cc[VTIME] = 1;
 		handle_errno(::ioctl(handle, TCSETS2, &ios));
 
-#elif __OpenBSD__
+#elif __OpenBSD__ || __NetBSD__
 		struct termios ios;
 		handle_errno(::tcgetattr(handle, &ios));
 		handle_errno(::cfsetspeed(&ios, baud_rate));

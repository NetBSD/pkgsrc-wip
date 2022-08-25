$NetBSD$

Treat NetBSD the same as OpenBSD.

--- src/libslic3r/GCodeSender.cpp.orig	2022-03-10 10:35:03.000000000 +0000
+++ src/libslic3r/GCodeSender.cpp
@@ -8,7 +8,7 @@
 #include <boost/date_time/posix_time/posix_time.hpp>
 #include <boost/lexical_cast.hpp>
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <termios.h>
 #endif
 #ifdef __APPLE__
@@ -146,7 +146,7 @@ GCodeSender::set_baud_rate(unsigned int 
         if (ioctl(handle, TCSETS2, &ios))
             printf("Error in TCSETS2: %s\n", strerror(errno));
 		
-#elif __OpenBSD__
+#elif __OpenBSD__ || __NetBSD__
 		struct termios ios;
 		::tcgetattr(handle, &ios);
 		::cfsetspeed(&ios, baud_rate);

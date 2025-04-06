$NetBSD$

Treat NetBSD the same as OpenBSD.

Fix boost 1.87 compatibility.
https://github.com/prusa3d/PrusaSlicer/issues/13799

--- src/libslic3r/GCodeSender.cpp.orig	2025-03-10 13:20:54.000000000 +0000
+++ src/libslic3r/GCodeSender.cpp
@@ -14,7 +14,7 @@
 #include <boost/date_time/posix_time/posix_time.hpp>
 #include <boost/lexical_cast.hpp>
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <termios.h>
 #endif
 #ifdef __APPLE__
@@ -113,7 +113,7 @@ GCodeSender::connect(std::string devname
     this->io.post(boost::bind(&GCodeSender::do_read, this));
     
     // start reading in the background thread
-    boost::thread t(boost::bind(&boost::asio::io_service::run, &this->io));
+    boost::thread t(boost::bind(&boost::asio::io_context::run, &this->io));
     this->background_thread.swap(t);
     
     // always send a M105 to check for connection because firmware might be silent on connect
@@ -152,7 +152,7 @@ GCodeSender::set_baud_rate(unsigned int 
         if (ioctl(handle, TCSETS2, &ios))
             printf("Error in TCSETS2: %s\n", strerror(errno));
 		
-#elif __OpenBSD__
+#elif __OpenBSD__ || __NetBSD__
 		struct termios ios;
 		::tcgetattr(handle, &ios);
 		::cfsetspeed(&ios, baud_rate);

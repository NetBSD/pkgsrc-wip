$NetBSD$

Fix boost 1.87 compatibility.
https://github.com/prusa3d/PrusaSlicer/issues/13799

--- src/libslic3r/GCodeSender.hpp.orig	2025-04-06 03:04:34.934454695 +0000
+++ src/libslic3r/GCodeSender.hpp
@@ -40,7 +40,7 @@ class GCodeSender : private boost::nonco
     void reset();
     
     private:
-    asio::io_service io;
+    asio::io_context io;
     asio::serial_port serial;
     boost::thread background_thread;
     boost::asio::streambuf read_buffer, write_buffer;

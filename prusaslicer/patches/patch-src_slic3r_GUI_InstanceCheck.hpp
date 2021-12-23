$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/InstanceCheck.hpp.orig	2021-12-17 14:00:02.000000000 +0000
+++ src/slic3r/GUI/InstanceCheck.hpp
@@ -11,7 +11,7 @@
 
 #include <boost/filesystem.hpp>
 
-#if __linux__
+#if defined(__linux__) || defined(__NetBSD__)
 #include <boost/thread.hpp>
 #include <mutex>
 #include <condition_variable>
@@ -38,7 +38,7 @@ namespace GUI {
 
 class MainFrame;
 
-#if __linux__
+#if defined(__linux__) || defined(__NetBSD__)
     #define BACKGROUND_MESSAGE_LISTENER
 #endif // __linux__
 

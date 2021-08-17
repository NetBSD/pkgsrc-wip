$NetBSD$

Remove use of deprecated tbb::mutex.

--- src/slic3r/GUI/InstanceCheck.hpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/slic3r/GUI/InstanceCheck.hpp
@@ -13,7 +13,6 @@
 
 #if __linux__
 #include <boost/thread.hpp>
-#include <tbb/mutex.h>
 #include <condition_variable>
 #endif // __linux__
 

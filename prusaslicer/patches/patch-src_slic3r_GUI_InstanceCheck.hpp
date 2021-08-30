$NetBSD$

Migrate away from features deprecated in tbb 2021.3.
Adapted from upstream git commit e13535f822b5efe0e3b471bc366e8d3ea96059d5.

--- src/slic3r/GUI/InstanceCheck.hpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/slic3r/GUI/InstanceCheck.hpp
@@ -13,7 +13,7 @@
 
 #if __linux__
 #include <boost/thread.hpp>
-#include <tbb/mutex.h>
+#include <mutex>
 #include <condition_variable>
 #endif // __linux__
 

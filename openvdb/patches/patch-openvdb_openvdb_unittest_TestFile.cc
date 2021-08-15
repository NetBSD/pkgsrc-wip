$NetBSD$

Support tbb 2021.3 from
https://github.com/AcademySoftwareFoundation/openvdb/commit/5b0ec82307c603adb147cee4bc1a925d407141f5

--- openvdb/openvdb/unittest/TestFile.cc.orig	2021-06-11 21:38:41.000000000 +0000
+++ openvdb/openvdb/unittest/TestFile.cc
@@ -13,8 +13,11 @@
 #include <openvdb/version.h>
 #include <openvdb/openvdb.h>
 #include "util.h" // for unittest_util::makeSphere()
+
 #include <gtest/gtest.h>
-#include <tbb/tbb_thread.h> // for tbb::this_tbb_thread::sleep()
+
+#include <thread>
+#include <chrono>
 #include <algorithm> // for std::sort()
 #include <cstdio> // for remove() and rename()
 #include <fstream>
@@ -2345,12 +2348,14 @@ TEST_F(TestFile, testAsync)
             helper.insert(id, filename);
         }
 
-        tbb::tick_count start = tbb::tick_count::now();
+        auto start = std::chrono::steady_clock::now();
         while (!helper.ids.empty()) {
-            if ((tbb::tick_count::now() - start).seconds() > 60) break; // time out after 1 minute
+            auto duration = std::chrono::duration_cast<std::chrono::seconds>(
+                std::chrono::steady_clock::now() - start);
+            if (size_t(duration.count()) > 60)  break; // time out after 1 minute
 
             // Wait one second for tasks to complete.
-            tbb::this_tbb_thread::sleep(tbb::tick_count::interval_t(1.0/*sec*/));
+            std::this_thread::sleep_for(std::chrono::seconds(1));
 
             // Poll each task in the pending map.
             std::set<io::Queue::Id> ids = helper.ids; // iterate over a copy
@@ -2380,7 +2385,7 @@ TEST_F(TestFile, testAsync)
             helper.insert(id, filename);
         }
         while (!queue.empty()) {
-            tbb::this_tbb_thread::sleep(tbb::tick_count::interval_t(1.0/*sec*/));
+            std::this_thread::sleep_for(std::chrono::seconds(1));
         }
     }
     {
@@ -2405,7 +2410,7 @@ TEST_F(TestFile, testAsync)
         EXPECT_THROW(queue.write(grids, io::Stream(file2)), openvdb::RuntimeError);
 
         while (!queue.empty()) {
-            tbb::this_tbb_thread::sleep(tbb::tick_count::interval_t(1.0/*sec*/));
+            std::this_thread::sleep_for(std::chrono::seconds(1));
         }
     }
 }

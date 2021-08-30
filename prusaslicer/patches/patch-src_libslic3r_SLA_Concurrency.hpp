$NetBSD$

Migrate away from features deprecated in tbb 2021.3.
Adapted from upstream git commit e13535f822b5efe0e3b471bc366e8d3ea96059d5.

--- src/libslic3r/SLA/Concurrency.hpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/libslic3r/SLA/Concurrency.hpp
@@ -2,11 +2,11 @@
 #define SLA_CONCURRENCY_H
 
 #include <tbb/spin_mutex.h>
-#include <tbb/mutex.h>
 #include <tbb/parallel_for.h>
 #include <tbb/parallel_reduce.h>
 
 #include <algorithm>
+#include <mutex>
 #include <numeric>
 
 #include <libslic3r/libslic3r.h>
@@ -23,7 +23,7 @@ template<bool> struct _ccr {};
 template<> struct _ccr<true>
 {
     using SpinningMutex = tbb::spin_mutex;
-    using BlockingMutex = tbb::mutex;
+    using BlockingMutex = std::mutex;
 
     template<class Fn, class It>
     static IteratorOnly<It, void> loop_(const tbb::blocked_range<It> &range, Fn &&fn)

$NetBSD$

Migrate from deprecated tbb::mutex to std::mutex.

--- src/libslic3r/SLA/Concurrency.hpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/libslic3r/SLA/Concurrency.hpp
@@ -2,7 +2,6 @@
 #define SLA_CONCURRENCY_H
 
 #include <tbb/spin_mutex.h>
-#include <tbb/mutex.h>
 #include <tbb/parallel_for.h>
 #include <tbb/parallel_reduce.h>
 
@@ -23,7 +22,7 @@ template<bool> struct _ccr {};
 template<> struct _ccr<true>
 {
     using SpinningMutex = tbb::spin_mutex;
-    using BlockingMutex = tbb::mutex;
+    using BlockingMutex = std::mutex;
 
     template<class Fn, class It>
     static IteratorOnly<It, void> loop_(const tbb::blocked_range<It> &range, Fn &&fn)

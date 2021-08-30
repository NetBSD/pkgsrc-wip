$NetBSD$

Migrate away from features deprecated in tbb 2021.3.
Adapted from upstream git commit e13535f822b5efe0e3b471bc366e8d3ea96059d5.

--- src/libslic3r/SupportMaterial.cpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/libslic3r/SupportMaterial.cpp
@@ -12,7 +12,6 @@
 #include <boost/log/trivial.hpp>
 
 #include <tbb/parallel_for.h>
-#include <tbb/atomic.h>
 #include <tbb/spin_mutex.h>
 #include <tbb/task_group.h>
 

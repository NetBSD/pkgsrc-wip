$NetBSD$

Migrate from deprecated tbb::mutex to std::mutex.

--- src/libslic3r/SLA/SupportTree.cpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/libslic3r/SLA/SupportTree.cpp
@@ -17,7 +17,6 @@
 #include <libnest2d/optimizers/nlopt/subplex.hpp>
 #include <boost/log/trivial.hpp>
 #include <tbb/parallel_for.h>
-#include <tbb/mutex.h>
 #include <tbb/spin_mutex.h>
 #include <libslic3r/I18N.hpp>
 

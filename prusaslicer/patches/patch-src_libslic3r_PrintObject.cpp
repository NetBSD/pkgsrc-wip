$NetBSD$

Migrate from deprecated tbb::atomic to std::atomic.

--- src/libslic3r/PrintObject.cpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/libslic3r/PrintObject.cpp
@@ -19,7 +19,6 @@
 #include <float.h>
 
 #include <tbb/parallel_for.h>
-#include <tbb/atomic.h>
 
 #include <Shiny/Shiny.h>
 

$NetBSD$

Migrate away from features deprecated in tbb 2021.3.
Adapted from upstream git commit e13535f822b5efe0e3b471bc366e8d3ea96059d5.

--- src/libslic3r/PrintObject.cpp.orig	2021-07-16 10:14:03.000000000 +0000
+++ src/libslic3r/PrintObject.cpp
@@ -19,7 +19,6 @@
 #include <float.h>
 
 #include <tbb/parallel_for.h>
-#include <tbb/atomic.h>
 
 #include <Shiny/Shiny.h>
 

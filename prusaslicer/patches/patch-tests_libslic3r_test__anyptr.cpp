$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_anyptr.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_anyptr.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #include <libslic3r/libslic3r.h>
 #include <libslic3r/AnyPtr.hpp>

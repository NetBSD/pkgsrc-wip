$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/fff_print/test_data.cpp.orig	2024-04-09 12:13:15.323843373 +0000
+++ tests/fff_print/test_data.cpp
@@ -399,7 +399,7 @@ bool contains_regex(const std::string &d
 
 } } // namespace Slic3r::Test
 
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 SCENARIO("init_print functionality", "[test_data]") {
 	GIVEN("A default config") {

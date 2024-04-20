$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/sla_print/sla_test_utils.hpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/sla_print/sla_test_utils.hpp
@@ -1,7 +1,9 @@
 #ifndef SLA_TEST_UTILS_HPP
 #define SLA_TEST_UTILS_HPP
 
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 #include <test_utils.hpp>
 
 // Debug

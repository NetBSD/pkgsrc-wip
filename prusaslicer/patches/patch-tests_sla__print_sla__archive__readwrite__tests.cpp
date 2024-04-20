$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/sla_print/sla_archive_readwrite_tests.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/sla_print/sla_archive_readwrite_tests.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <test_utils.hpp>
 
 #include "libslic3r/SLAPrint.hpp"

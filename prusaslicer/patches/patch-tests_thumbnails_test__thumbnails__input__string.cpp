$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/thumbnails/test_thumbnails_input_string.cpp.orig	2024-04-14 02:13:15.066070658 +0000
+++ tests/thumbnails/test_thumbnails_input_string.cpp
@@ -1,4 +1,4 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <test_utils.hpp>
 
 #include <libslic3r/GCode/Thumbnails.hpp>
@@ -149,4 +149,4 @@ TEST_CASE("Invalid value Thumbnails", "[
         REQUIRE(errors.has(ThumbnailError::InvalidVal));
         REQUIRE(thumbnails.size() == 2);
     }
-}
\ No newline at end of file
+}

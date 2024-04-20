$NetBSD$

Support Catch2 v3.
Based on https://github.com/prusa3d/PrusaSlicer/issues/11567

--- tests/libslic3r/test_clipper_offset.cpp.orig	2024-02-29 13:03:32.000000000 +0000
+++ tests/libslic3r/test_clipper_offset.cpp
@@ -1,4 +1,6 @@
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
+#include <catch2/matchers/catch_matchers.hpp>
+#include <catch2/matchers/catch_matchers_floating_point.hpp>
 
 #include <iostream>
 #include <boost/filesystem.hpp>
@@ -8,6 +10,7 @@
 #include "libslic3r/SVG.hpp"
 
 using namespace Slic3r;
+using Catch::Matchers::WithinRel;
 
 // #define TESTS_EXPORT_SVGS
 
@@ -32,7 +35,7 @@ SCENARIO("Constant offset", "[ClipperUti
 #endif
 					THEN("Area is 22^2mm2") {
 						REQUIRE(output.size() == 1);
-						REQUIRE(output.front().area() == Approx(22. * 22. * s * s));
+						REQUIRE_THAT(output.front().area(), WithinRel(22. * 22. * s * s));
 					}
 				}
 				DYNAMIC_SECTION("minus 1mm, miter " << miter << "x") {
@@ -46,7 +49,7 @@ SCENARIO("Constant offset", "[ClipperUti
 #endif
 					THEN("Area is 18^2mm2") {
 						REQUIRE(output.size() == 1);
-						REQUIRE(output.front().area() == Approx(18. * 18. * s * s));
+						REQUIRE_THAT(output.front().area(), WithinRel(18. * 18. * s * s));
 					}
 				}
 			}
@@ -64,7 +67,7 @@ SCENARIO("Constant offset", "[ClipperUti
 #endif
 					THEN("Area is 22^2mm2") {
 						REQUIRE(output.size() == 1);
-						REQUIRE(output.front().area() == Approx(22. * 22. * s * s));
+						REQUIRE_THAT(output.front().area(), WithinRel(22. * 22. * s * s));
 					}
 				}
 				DYNAMIC_SECTION("minus 1mm, miter " << miter << "x") {
@@ -78,7 +81,7 @@ SCENARIO("Constant offset", "[ClipperUti
 #endif
 					THEN("Area is 18^2mm2") {
 						REQUIRE(output.size() == 1);
-						REQUIRE(output.front().area() == Approx(18. * 18. * s * s));
+						REQUIRE_THAT(output.front().area(), WithinRel(18. * 18. * s * s));
 					}
 				}
 			}
@@ -106,7 +109,7 @@ SCENARIO("Constant offset", "[ClipperUti
 #endif
 						THEN("Area is 22^2-8^2 mm2") {
 							REQUIRE(output.size() == 1);
-							REQUIRE(output.front().area() == Approx((22. * 22. - 8. * 8.) * s * s));
+							REQUIRE_THAT(output.front().area(), WithinRel((22. * 22. - 8. * 8.) * s * s));
 						}
 					}
 					WHEN("minus 1mm") {
@@ -120,7 +123,7 @@ SCENARIO("Constant offset", "[ClipperUti
 #endif
 						THEN("Area is 18^2-12^2 mm2") {
 							REQUIRE(output.size() == 1);
-							REQUIRE(output.front().area() == Approx((18. * 18. - 12. * 12.) * s * s));
+							REQUIRE_THAT(output.front().area(), WithinRel((18. * 18. - 12. * 12.) * s * s));
 						}
 					}
 				}
@@ -140,7 +143,7 @@ SCENARIO("Constant offset", "[ClipperUti
 #endif
 						THEN("Area is 22^2-8^2 mm2") {
 							REQUIRE(output.size() == 1);
-							REQUIRE(output.front().area() == Approx((22. * 22. - 8. * 8.) * s * s));
+							REQUIRE_THAT(output.front().area(), WithinRel((22. * 22. - 8. * 8.) * s * s));
 						}
 					}
 					WHEN("minus 1mm") {
@@ -154,7 +157,7 @@ SCENARIO("Constant offset", "[ClipperUti
 #endif
 						THEN("Area is 18^2-12^2 mm2") {
 							REQUIRE(output.size() == 1);
-							REQUIRE(output.front().area() == Approx((18. * 18. - 12. * 12.) * s * s));
+							REQUIRE_THAT(output.front().area(), WithinRel((18. * 18. - 12. * 12.) * s * s));
 						}
 					}
 				}
@@ -186,7 +189,7 @@ SCENARIO("Constant offset", "[ClipperUti
 #endif
 					THEN("Area matches") {
 						REQUIRE(output.size() == 1);
-						REQUIRE(output.front().area() == Approx(area_offsetted));
+						REQUIRE_THAT(output.front().area(), WithinRel(area_offsetted, EPSILON));
 					}
 				}
 			}
@@ -205,7 +208,7 @@ SCENARIO("Constant offset", "[ClipperUti
 #endif
 					THEN("Area matches") {
 						REQUIRE(output.size() == 1);
-						REQUIRE(output.front().area() == Approx(area_offsetted));
+						REQUIRE_THAT(output.front().area(), WithinRel(area_offsetted, EPSILON));
 					}
 				}
 			}

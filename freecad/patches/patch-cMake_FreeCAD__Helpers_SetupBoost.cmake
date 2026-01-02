$NetBSD$

--- cMake/FreeCAD_Helpers/SetupBoost.cmake.orig	2026-01-01 11:41:33.764483505 +0000
+++ cMake/FreeCAD_Helpers/SetupBoost.cmake
@@ -3,7 +3,7 @@ macro(SetupBoost)
 
     set(_boost_TEST_VERSIONS ${Boost_ADDITIONAL_VERSIONS})
 
-    set (BOOST_COMPONENTS filesystem program_options regex system thread date_time)
+    set (BOOST_COMPONENTS filesystem program_options regex thread date_time)
     find_package(Boost ${BOOST_MIN_VERSION}
         COMPONENTS ${BOOST_COMPONENTS} REQUIRED)
 

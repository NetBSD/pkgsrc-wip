$NetBSD$

Fix build with latest CGAL/boost.

--- src/libslic3r/Geometry/VoronoiUtilsCgal.cpp.orig	2026-03-13 22:56:17.138721281 +0000
+++ src/libslic3r/Geometry/VoronoiUtilsCgal.cpp
@@ -2,6 +2,9 @@
 ///|/
 ///|/ PrusaSlicer is released under the terms of the AGPLv3 or higher
 ///|/
+
+#include <boost/mpl/if.hpp>
+
 #include <CGAL/Exact_predicates_exact_constructions_kernel.h>
 #include <CGAL/Arr_segment_traits_2.h>
 #include <CGAL/Surface_sweep_2_algorithms.h>
@@ -333,4 +336,4 @@ VoronoiUtilsCgal::is_voronoi_diagram_pla
     return true;
 }
 
-} // namespace Slic3r::Geometry
\ No newline at end of file
+} // namespace Slic3r::Geometry

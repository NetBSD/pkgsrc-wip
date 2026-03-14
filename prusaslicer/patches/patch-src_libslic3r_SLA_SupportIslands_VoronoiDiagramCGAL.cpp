$NetBSD$

Fix build with latest CGAL/boost.

--- src/libslic3r/SLA/SupportIslands/VoronoiDiagramCGAL.cpp.orig	2026-03-13 23:33:14.225710102 +0000
+++ src/libslic3r/SLA/SupportIslands/VoronoiDiagramCGAL.cpp
@@ -2,6 +2,8 @@
 
 #include <iostream>
 
+#include <boost/mpl/if.hpp>
+
 // includes for defining the Voronoi diagram adaptor
 #include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
 #include <CGAL/Delaunay_triangulation_2.h>
@@ -291,4 +293,4 @@ Polygons Slic3r::sla::create_voronoi_cel
     // Point_2 p;
     // Locate_result lr = vd.locate(p); // Could locate face of VD - potentionaly could iterate input points
     return cells;
-}
\ No newline at end of file
+}

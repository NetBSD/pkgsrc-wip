$NetBSD$

Fix build with latest CGAL/boost.

--- src/libslic3r/Triangulation.cpp.orig	2026-03-13 23:34:05.018315614 +0000
+++ src/libslic3r/Triangulation.cpp
@@ -4,6 +4,8 @@
 ///|/
 #include "Triangulation.hpp"
 
+#include <boost/mpl/if.hpp>
+
 #include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
 #include <CGAL/Constrained_Delaunay_triangulation_2.h>
 #include <CGAL/Triangulation_vertex_base_with_info_2.h>

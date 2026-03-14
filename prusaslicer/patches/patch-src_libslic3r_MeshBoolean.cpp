$NetBSD$

Fix build with latest CGAL/boost.

--- src/libslic3r/MeshBoolean.cpp.orig	2026-03-13 23:05:27.737938407 +0000
+++ src/libslic3r/MeshBoolean.cpp
@@ -10,6 +10,8 @@
 
 #undef PI
 
+#include <boost/mpl/if.hpp>
+
 // Include igl first. It defines "L" macro which then clashes with our localization
 #include <igl/copyleft/cgal/mesh_boolean.h> // IWYU pragma: keep
 #include <igl/MeshBooleanType.h>

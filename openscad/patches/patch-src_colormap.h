$NetBSD$

--- src/colormap.h.orig	2018-03-13 12:12:43.000000000 +0000
+++ src/colormap.h
@@ -6,9 +6,10 @@
 #include "linalg.h"
 
 #include "memory.h"
+#ifndef Q_MOC_RUN
 #include <boost/filesystem.hpp>
 #include <boost/property_tree/ptree.hpp>
-
+#endif
 namespace fs = boost::filesystem;
 
 enum class RenderColor {

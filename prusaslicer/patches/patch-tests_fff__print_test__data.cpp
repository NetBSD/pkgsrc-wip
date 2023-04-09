$NetBSD$

Missing include.

--- tests/fff_print/test_data.cpp.orig	2023-03-13 13:20:26.000000000 +0000
+++ tests/fff_print/test_data.cpp
@@ -8,6 +8,7 @@
 #include "libslic3r/Format/STL.hpp"
 
 #include <cstdlib>
+#include <fstream>
 #include <string>
 
 #include <boost/nowide/cstdio.hpp>

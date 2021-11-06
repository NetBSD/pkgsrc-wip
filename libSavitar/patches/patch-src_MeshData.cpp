$NetBSD$

https://github.com/Ultimaker/libSavitar/commit/91aa70c6320461ae65600dce954b5ffb905b7039.patch

Do not vendor the pugixml library

This prevents trying to co-install pugixml with existing system
libraries, and also fixes the includes for pugixml.hpp to actually use
the include path added by find_package/add_subdirectory instead of a
hardcoded relative path.

--- src/MeshData.cpp.orig	2021-05-10 11:47:11.000000000 +0000
+++ src/MeshData.cpp
@@ -17,7 +17,7 @@
  */
 
 #include "MeshData.h"
-#include "../pugixml/src/pugixml.hpp"
+#include <pugixml.hpp>
 #include <cstring>
 #include <iostream>
 #include <stdexcept> //For std::runtime_error.
@@ -222,6 +222,3 @@ std::vector< Vertex > MeshData::getVerti
 {
     return vertices;
 }
-
-
-

$NetBSD$

https://github.com/Ultimaker/libSavitar/commit/91aa70c6320461ae65600dce954b5ffb905b7039.patch

Do not vendor the pugixml library

This prevents trying to co-install pugixml with existing system
libraries, and also fixes the includes for pugixml.hpp to actually use
the include path added by find_package/add_subdirectory instead of a
hardcoded relative path.

--- src/SceneNode.cpp.orig	2020-10-09 16:43:31.000000000 +0000
+++ src/SceneNode.cpp
@@ -18,7 +18,7 @@
 
 #include "SceneNode.h"
 #include "Namespace.h"
-#include "../pugixml/src/pugixml.hpp"
+#include <pugixml.hpp>
 #include <iostream>
 using namespace Savitar;
 
@@ -200,4 +200,3 @@ std::vector< SceneNode*> SceneNode::getA
     all_children.insert(all_children.end(), children.begin(), children.end());
     return all_children;
 }
-

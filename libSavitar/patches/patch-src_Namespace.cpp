$NetBSD$

https://github.com/Ultimaker/libSavitar/commit/91aa70c6320461ae65600dce954b5ffb905b7039.patch

Do not vendor the pugixml library

This prevents trying to co-install pugixml with existing system
libraries, and also fixes the includes for pugixml.hpp to actually use
the include path added by find_package/add_subdirectory instead of a
hardcoded relative path.

--- src/Namespace.cpp.orig	2021-02-11 05:48:18.522781994 +0000
+++ src/Namespace.cpp
@@ -3,7 +3,7 @@
 
 #include "Namespace.h"
 
-#include "../pugixml/src/pugixml.hpp"
+#include <pugixml.hpp>
 
 namespace xml_namespace
 {

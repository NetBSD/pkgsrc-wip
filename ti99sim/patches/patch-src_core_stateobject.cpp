$NetBSD$

--- src/core/stateobject.cpp.orig	2024-10-03 22:18:01 UTC
+++ src/core/stateobject.cpp
@@ -31,6 +31,7 @@
 #include <cstdio>
 #include <iomanip>
 #include <fstream>
+#include <sstream>
 #include "common.hpp"
 #include "logger.hpp"
 #include "stateobject.hpp"

$NetBSD$

--- tools/testrunner/main.cpp.orig	2021-09-12 00:15:52.000000000 +0000
+++ tools/testrunner/main.cpp
@@ -14,6 +14,7 @@
 #include <vector>
 #include <fstream>
 #include <cctype>   // std::isblank
+#include <csignal>
 #include "../common/debug.h"
 #include "../common/path.h"
 #ifdef _WIN32

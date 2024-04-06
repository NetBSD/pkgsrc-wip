$NetBSD$

Support Catch2 v3.

--- tests/core/core_tests.cpp.orig	2024-04-06 07:42:50.424323910 +0000
+++ tests/core/core_tests.cpp
@@ -2,6 +2,8 @@
 
 #include "core/core.hpp"
 
+#include <iostream>
+
 #include <boost/nowide/cstdio.hpp>
 
 using namespace bgcode::core;

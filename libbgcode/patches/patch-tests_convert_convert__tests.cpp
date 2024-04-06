$NetBSD$

Support Catch2 v3.

--- tests/convert/convert_tests.cpp.orig	2024-04-06 07:43:35.839605465 +0000
+++ tests/convert/convert_tests.cpp
@@ -3,6 +3,7 @@
 #include "convert/convert.hpp"
 
 #include <fstream>
+#include <iostream>
 
 #include <boost/nowide/cstdio.hpp>
 

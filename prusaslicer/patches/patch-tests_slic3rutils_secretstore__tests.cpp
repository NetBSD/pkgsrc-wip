$NetBSD$

Support Catch2 v3.

--- tests/slic3rutils/secretstore_tests.cpp.orig	2024-06-16 00:22:38.655124085 +0000
+++ tests/slic3rutils/secretstore_tests.cpp
@@ -1,4 +1,4 @@
-#include "catch2/catch.hpp"
+#include "catch2/catch_test_macros.hpp"
 
 #include "slic3r/Utils/Secrets.hpp"
 

$NetBSD$

Support Catch2 v3.

--- tests/catch_main.hpp.orig	2024-04-06 07:39:45.253486614 +0000
+++ tests/catch_main.hpp
@@ -3,6 +3,6 @@
 
 #define CATCH_CONFIG_EXTERNAL_INTERFACES
 #define CATCH_CONFIG_MAIN
-#include <catch2/catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 
 #endif // CATCH_MAIN

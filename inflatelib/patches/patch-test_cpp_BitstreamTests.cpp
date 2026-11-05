$NetBSD$

https://github.com/microsoft/inflatelib/pull/36

--- test/cpp/BitstreamTests.cpp.orig	2026-08-21 23:40:16.000000000 +0000
+++ test/cpp/BitstreamTests.cpp
@@ -6,7 +6,7 @@
  *    TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  *    PARTICULAR PURPOSE AND NONINFRINGEMENT.
  */
-#include <catch.hpp>
+#include <catch2/catch_test_macros.hpp>
 #include <span>
 
 #include <bitstream.h>

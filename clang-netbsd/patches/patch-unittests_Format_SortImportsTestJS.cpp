$NetBSD$

--- unittests/Format/SortImportsTestJS.cpp.orig	2016-12-17 00:12:47.000000000 +0000
+++ unittests/Format/SortImportsTestJS.cpp
@@ -38,7 +38,7 @@ protected:
                   unsigned Offset = 0, unsigned Length = 0) {
     std::string Result = sort(Code, Offset, Length);
     EXPECT_EQ(Expected.str(), Result) << "Expected:\n"
-                                      << Expected << "\nActual:\n"
+                                      << Expected.str() << "\nActual:\n"
                                       << Result;
   }
 

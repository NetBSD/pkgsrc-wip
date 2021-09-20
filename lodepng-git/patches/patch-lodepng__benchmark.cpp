$NetBSD$

lodepng_benchmark.cpp:86:10: error: 'exit' is not a member of 'std'; did you mean 'exit'?

--- lodepng_benchmark.cpp.orig	2021-09-20 15:32:18.000000000 +0000
+++ lodepng_benchmark.cpp
@@ -75,7 +75,7 @@ void assertEquals(const T& expected, con
   if(expected != (T)actual) {
     std::cout << "Error: Not equal! Expected " << expected << " got " << actual << "." << std::endl;
     std::cout << "Message: " << message << std::endl;
-    std::exit(1);
+    exit(1);
   }
 }
 
@@ -83,7 +83,7 @@ void assertTrue(bool value, const std::s
   if(!value) {
     std::cout << "Error: expected true." << std::endl;
     std::cout << "Message: " << message << std::endl;
-    std::exit(1);
+    exit(1);
   }
 }
 

$NetBSD$

--- test/fuzzer/NullDerefTest.cpp.orig	2018-06-07 08:27:17.000000000 +0000
+++ test/fuzzer/NullDerefTest.cpp
@@ -23,4 +23,3 @@ extern "C" int LLVMFuzzerTestOneInput(co
   }
   return 0;
 }
-

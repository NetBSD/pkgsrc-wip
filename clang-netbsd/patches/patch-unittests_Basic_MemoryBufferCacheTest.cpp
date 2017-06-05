$NetBSD$

--- unittests/Basic/MemoryBufferCacheTest.cpp.orig	2017-03-22 16:58:38.000000000 +0000
+++ unittests/Basic/MemoryBufferCacheTest.cpp
@@ -9,6 +9,7 @@
 
 #include "clang/Basic/MemoryBufferCache.h"
 #include "llvm/Support/MemoryBuffer.h"
+#include "llvm/Support/raw_ostream.h"
 #include "gtest/gtest.h"
 
 using namespace llvm;

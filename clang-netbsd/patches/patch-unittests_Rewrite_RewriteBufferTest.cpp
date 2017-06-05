$NetBSD$

--- unittests/Rewrite/RewriteBufferTest.cpp.orig	2016-12-17 00:12:45.000000000 +0000
+++ unittests/Rewrite/RewriteBufferTest.cpp
@@ -8,6 +8,7 @@
 //===----------------------------------------------------------------------===//
 
 #include "clang/Rewrite/Core/RewriteBuffer.h"
+#include "llvm/Support/raw_ostream.h"
 #include "gtest/gtest.h"
 
 using namespace llvm;

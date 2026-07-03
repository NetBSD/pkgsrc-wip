$NetBSD$

Avoid
c10/test/core/Scalar_test.cpp: In member function 'virtual void ScalarTest_LongsAndLongLongs_Test::TestBody()':
c10/test/core/Scalar_test.cpp:53:24: error: conversion from 'long long int' to 'c10::Scalar' is ambiguous
   53 |   Scalar longlongOne = 1LL;

https://github.com/pytorch/pytorch/issues/188911

--- c10/test/core/Scalar_test.cpp.orig	2026-07-03 14:48:13.006025245 +0000
+++ c10/test/core/Scalar_test.cpp
@@ -50,6 +50,6 @@ TEST(ScalarTest, LongsAndLongLongs) {
 
 TEST(ScalarTest, LongsAndLongLongs) {
   Scalar longOne = 1L;
-  Scalar longlongOne = 1LL;
+  Scalar longlongOne = (uint64_t)1LL;
   ASSERT_EQ(longOne.toInt(), longlongOne.toInt());
 }

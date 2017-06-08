$NetBSD$

--- test/Sema/128bitfloat.cpp.orig	2017-05-29 10:06:54.000000000 +0000
+++ test/Sema/128bitfloat.cpp
@@ -4,6 +4,8 @@
 // RUN: %clang_cc1 -triple i686-windows-gnu -verify -std=c++11 %s
 // RUN: %clang_cc1 -triple x86_64-windows-gnu -verify -std=c++11 %s
 // RUN: %clang_cc1 -triple x86_64-windows-msvc -verify -std=c++11 %s
+// RUN: %clang_cc1 -triple i386--netbsd -verify -std=c++11 %s
+// RUN: %clang_cc1 -triple x86_64--netbsd -verify -std=c++11 %s
 
 #if defined(__FLOAT128__) || defined(__SIZEOF_FLOAT128__)
 __float128 f;

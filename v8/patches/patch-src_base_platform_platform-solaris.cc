$NetBSD: patch-src_base_platform_platform-solaris.cc,v 1.1 2014/08/25 13:22:01 fhajny Exp $

Avoid conflicting with definitions in GCC includes.

--- src/base/platform/platform-solaris.cc.orig	2014-08-08 13:04:31.000000000 +0000
+++ src/base/platform/platform-solaris.cc
@@ -9,6 +9,7 @@
 # error "V8 does not support the SPARC CPU architecture."
 #endif
 
+#include <alloca.h>
 #include <dlfcn.h>  // dladdr
 #include <errno.h>
 #include <ieeefp.h>  // finite()
@@ -34,7 +35,7 @@
 // It seems there is a bug in some Solaris distributions (experienced in
 // SunOS 5.10 Generic_141445-09) which make it difficult or impossible to
 // access signbit() despite the availability of other C99 math functions.
-#ifndef signbit
+#if !defined(signbit) && !defined(_GLIBCXX_USE_C99_MATH)
 namespace std {
 // Test sign - usually defined in math.h
 int signbit(double x) {

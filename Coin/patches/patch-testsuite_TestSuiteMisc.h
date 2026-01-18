$NetBSD$

fixed build with boost 1.90 beta 1

https://github.com/coin3d/coin/commit/1bba57bd0d9f41666d72857f75263068aeeeefcb

--- testsuite/TestSuiteMisc.h.orig	2026-01-15 14:30:06.460664268 +0000
+++ testsuite/TestSuiteMisc.h
@@ -36,6 +36,7 @@
 #include <string>
 #include <ostream>
 #include <boost/lexical_cast.hpp>
+#include <boost/static_assert.hpp>
 #include <Inventor/SbBasic.h>
 #include <Inventor/SbTypeInfo.h>
 

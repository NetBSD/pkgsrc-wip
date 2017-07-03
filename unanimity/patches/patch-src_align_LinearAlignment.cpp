$NetBSD$

# Work around a boost ublas heade bug

--- src/align/LinearAlignment.cpp.orig	2016-09-12 19:55:43.000000000 +0000
+++ src/align/LinearAlignment.cpp
@@ -53,6 +53,9 @@
 #include <string>
 #include <vector>
 
+// Bug workaround: https://stackoverflow.com/questions/44534516/error-make-array-is-not-a-member-of-boostserialization
+#include <boost/serialization/array_wrapper.hpp>
+
 #include <boost/numeric/ublas/io.hpp>
 #include <boost/numeric/ublas/matrix.hpp>
 #include <boost/numeric/ublas/vector.hpp>

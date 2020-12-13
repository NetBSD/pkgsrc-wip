$NetBSD$

* fix compatability errors

--- m4macros/ax_gtest.m4.orig	2020-11-03 13:32:31.000000000 +0000
+++ m4macros/ax_gtest.m4
@@ -100,7 +100,7 @@ if test "x$enable_gtest" = "xyes" ; then
 
 # Versions starting from 1.8.0 are put in the googletest directory. If the basename
 # returns googletest string, we need to cut it off and try baseline again.
-        if test "$GTEST_VERSION" == "googletest"; then
+        if test "$GTEST_VERSION" = "googletest"; then
             GTEST_VERSION=${GTEST_SOURCE%"/googletest"}
             GTEST_VERSION=`basename $GTEST_VERSION`
         fi

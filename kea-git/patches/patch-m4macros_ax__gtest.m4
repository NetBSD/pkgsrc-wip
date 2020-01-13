$NetBSD$

* fix typo so that googletest can be found

--- m4macros/ax_gtest.m4.orig	2020-01-02 23:01:48.000000000 +0000
+++ m4macros/ax_gtest.m4
@@ -134,7 +134,7 @@ if test "x$enable_gtest" = "xyes" ; then
             GTEST_FOUND="false"
             for dir in $GTEST_PATHS; do
                 if test -f "$dir/include/gtest/gtest.h"; then
-                    if ! test -f "$dir/lib/libgtests.a"; then
+                    if ! test -f "$dir/lib/libgtest.a"; then
                         AC_MSG_WARN([Found Google Test include but not the library in $dir.])
                         continue
                     fi

$NetBSD$

test == is not portable.

--- autoconf/hercules.m4.orig	2019-09-10 18:06:20.000000000 +0000
+++ autoconf/hercules.m4
@@ -187,7 +187,7 @@ AC_DEFUN( [HC_GET_C11_LOCK_FREE_VALUE],
 [
     c11_lock_free_name="$1"
 
-    if test "x$c11_lock_free_name" == "x"; then
+    if test "x$c11_lock_free_name" = "x"; then
         # PROGRAMMING NOTE: note special m4 escape syntax used in the below
         # message. Without it, our function name is (infinitely and recursively?)
         # expanded to our actual (as-yet not yet fully defined!) macro VALUE(!),

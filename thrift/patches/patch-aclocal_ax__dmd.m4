$NetBSD$

Fix portability.

--- aclocal/ax_dmd.m4.orig	2015-10-01 17:16:28.000000000 +0000
+++ aclocal/ax_dmd.m4
@@ -67,7 +67,7 @@ AC_DEFUN([AX_DMD],
 
           # Test whether OPTLINK is used by trying if DMD accepts -L/? without
           # erroring out.
-          if test "$success" == "yes" ; then
+          if test "$success" = "yes" ; then
             AC_MSG_CHECKING(whether DMD uses OPTLINK)
             echo "Running \”$DMD -L/? configtest_ax_dmd.d\"" >&AS_MESSAGE_LOG_FD
             if $DMD -L/? configtest_ax_dmd.d >&AS_MESSAGE_LOG_FD 2>&1 ; then

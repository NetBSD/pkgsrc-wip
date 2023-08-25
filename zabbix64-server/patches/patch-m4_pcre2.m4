$NetBSD$

Fix bash-isms.

--- m4/pcre2.m4.orig	2023-08-22 08:10:21.991666838 +0000
+++ m4/pcre2.m4
@@ -195,7 +195,7 @@ AS_HELP_STRING([--with-libpcre2@<:@=DIR@
 		if test "x$enable_static" = "xyes"; then
 			LIBPCRE2_LIBS=" $LIBPCRE2_LIBS -lpthread"
 		elif test "x$enable_static_libs" = "xyes"; then
-			if test "x$static_linking_support" == "xno"; then
+			if test "x$static_linking_support" = "xno"; then
 				AC_MSG_WARN([compiler has no direct suppor for static linkage])
 
 				if test -n "$libpcre2_lib_dir"; then

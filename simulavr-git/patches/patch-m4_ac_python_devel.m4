$NetBSD: patch-m4_ac_python_devel.m4,v 1.1 2013/08/08 05:41:39 makoto Exp $

=> Checking for portability problems in extracted files
ERROR: [check-portability.awk] => Found test ... == ...:

--- m4/ac_python_devel.m4.orig	2013-08-08 09:25:31.000000000 +0900
+++ m4/ac_python_devel.m4	2013-08-08 09:39:22.000000000 +0900
@@ -182,7 +182,7 @@ $ac_distutils_result])
 		py_version=`$PYTHON -c "from distutils.sysconfig import *; \
 			from string import join; \
 			print(join(get_config_vars('VERSION')))"`
-		if test "$py_version" == "[None]"; then
+		if test "$py_version" = "[None]"; then
 			if test -n "$PYTHON_VERSION"; then
 				py_version=$PYTHON_VERSION
 			else

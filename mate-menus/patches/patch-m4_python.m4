$NetBSD: patch-m4_python.m4,v 1.1 2015/01/01 08:17:39 obache Exp $

* test(1) portability fix

--- m4/python.m4.orig	2013-02-13 22:51:45.000000000 +0000
+++ m4/python.m4
@@ -34,7 +34,7 @@ AC_MSG_CHECKING(for python libraries)
 dnl Check whether python was compiled as shared library
 link_pymodules_libpython=false;
 py_enable_shared=`$PYTHON -c "from distutils.sysconfig import get_config_var; print repr(get_config_var('Py_ENABLE_SHARED'))"`
-if test $py_enable_shared == 1 ; then
+if test $py_enable_shared = 1 ; then
   if test x`uname -s` != xDarwin; then
       PYTHON_LDFLAGS="-no-undefined"
       link_pymodules_libpython=true;

$NetBSD$

Let's be hopeful.

--- ueberzug/X/python.h.orig	2025-02-11 14:11:43.514334671 +0000
+++ ueberzug/X/python.h
@@ -1,10 +1,6 @@
 #ifndef __PYTHON_H__
 #define __PYTHON_H__
 
-#ifndef __linux__
-#error OS unsupported
-#endif
-
 #define PY_SSIZE_T_CLEAN  // Make "s#" use Py_ssize_t rather than int.
 #include <Python.h>
 

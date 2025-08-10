$NetBSD: patch-Modules_FindPythonLibs.cmake,v 1.1 2017/07/19 17:44:34 adam Exp $

Insist on select python version for pkgsrc.

--- Modules/FindPythonLibs.cmake.orig	2014-12-15 20:07:43.000000000 +0000
+++ Modules/FindPythonLibs.cmake
@@ -82,6 +82,13 @@ else()
     set(_PYTHON_FIND_OTHER_VERSIONS ${_PYTHON3_VERSIONS} ${_PYTHON2_VERSIONS} ${_PYTHON1_VERSIONS})
 endif()
 
+# for pkgsrc: force Python version (set in pyversion.mk)
+if(DEFINED PYVERSSUFFIX)
+  set(_VERSIONS ${PYVERSSUFFIX})
+else()
+  set(_VERSIONS ${_PYTHON2_VERSIONS} ${_PYTHON3_VERSIONS})
+endif()
+
 # Set up the versions we know about, in the order we will search. Always add
 # the user supplied additional versions to the front.
 # If FindPythonInterp has already found the major and minor version,
@@ -91,7 +98,7 @@ set(_Python_VERSIONS ${Python_ADDITIONAL
 if(DEFINED PYTHON_VERSION_MAJOR AND DEFINED PYTHON_VERSION_MINOR)
   list(APPEND _Python_VERSIONS ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR})
 endif()
-list(APPEND _Python_VERSIONS ${_PYTHON_FIND_OTHER_VERSIONS})
+list(APPEND _Python_VERSIONS ${_VERSIONS})
 
 unset(_PYTHON_FIND_OTHER_VERSIONS)
 unset(_PYTHON1_VERSIONS)

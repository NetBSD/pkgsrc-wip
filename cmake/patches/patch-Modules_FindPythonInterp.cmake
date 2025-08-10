$NetBSD: patch-Modules_FindPythonInterp.cmake,v 1.1 2017/07/19 17:44:34 adam Exp $

Insist on select python version for pkgsrc.

--- Modules/FindPythonInterp.cmake.orig	2014-12-15 20:07:43.000000000 +0000
+++ Modules/FindPythonInterp.cmake
@@ -75,7 +75,14 @@ if(PythonInterp_FIND_VERSION)
 else()
     set(_PYTHON_FIND_OTHER_VERSIONS ${_PYTHON3_VERSIONS} ${_PYTHON2_VERSIONS} ${_PYTHON1_VERSIONS})
 endif()
-find_program(PYTHON_EXECUTABLE NAMES ${_Python_NAMES})
+# for pkgsrc: force Python version (set in pyversion.mk)
+IF(DEFINED PYVERSSUFFIX)
+  SET(_VERSIONS ${PYVERSSUFFIX})
+ELSE(DEFINED PYVERSSUFFIX)
+  SET(_VERSIONS ${_PYTHON2_VERSIONS} ${_PYTHON3_VERSIONS})
+  # Search for the current active python version first
+  find_program(PYTHON_EXECUTABLE NAMES python)
+ENDIF(DEFINED PYVERSSUFFIX)
 
 # Set up the versions we know about, in the order we will search. Always add
 # the user supplied additional versions to the front.
@@ -91,7 +98,7 @@ if(DEFINED PYTHONLIBS_VERSION_STRING)
 endif()
 # Search for the current active python version first
 list(APPEND _Python_VERSIONS ";")
-list(APPEND _Python_VERSIONS ${_PYTHON_FIND_OTHER_VERSIONS})
+list(APPEND _Python_VERSIONS ${_VERSIONS})
 
 unset(_PYTHON_FIND_OTHER_VERSIONS)
 unset(_PYTHON1_VERSIONS)

$NetBSD$

* add function so that libraries such as socket and nsl 
  can be added to tests

--- cmake/QtProcessConfigureArgs.cmake.orig	2021-01-26 18:29:22.000000000 +0000
+++ cmake/QtProcessConfigureArgs.cmake
@@ -133,7 +133,7 @@ defstub(qt_feature_definition)
 defstub(qt_find_package)
 defstub(set_package_properties)
 defstub(qt_qml_find_python)
-
+defstub(qt_test_lib_target)
 
 ####################################################################################################
 # Define functions/macros that are called in qt_cmdline.cmake files

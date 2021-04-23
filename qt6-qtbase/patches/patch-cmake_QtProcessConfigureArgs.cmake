$NetBSD$

* add function so that libraries such as socket and nsl 
  can be added to tests

* add support for avoiding the cmake archiving api using configure since
  libarchive in pkgsrc that cmake uses is built without zstd support

--- cmake/QtProcessConfigureArgs.cmake.orig	2021-02-11 10:23:05.000000000 +0000
+++ cmake/QtProcessConfigureArgs.cmake
@@ -133,7 +133,7 @@ defstub(qt_feature_definition)
 defstub(qt_find_package)
 defstub(set_package_properties)
 defstub(qt_qml_find_python)
-
+defstub(qt_test_lib_target)
 
 ####################################################################################################
 # Define functions/macros that are called in qt_cmdline.cmake files
@@ -633,6 +633,7 @@ translate_boolean_input(precompile_heade
 translate_boolean_input(ccache QT_USE_CCACHE)
 translate_boolean_input(shared BUILD_SHARED_LIBS)
 translate_boolean_input(warnings_are_errors WARNINGS_ARE_ERRORS)
+translate_boolean_input(avoid_cmake_archiving_api QT_AVOID_CMAKE_ARCHIVING_API)
 translate_string_input(qt_namespace QT_NAMESPACE)
 translate_string_input(qt_libinfix QT_LIBINFIX)
 translate_string_input(qreal QT_COORD_TYPE)

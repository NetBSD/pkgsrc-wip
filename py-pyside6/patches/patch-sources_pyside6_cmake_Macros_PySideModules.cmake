$NetBSD$

--- sources/pyside6/cmake/Macros/PySideModules.cmake.orig	2025-11-18 11:43:26.000000000 +0000
+++ sources/pyside6/cmake/Macros/PySideModules.cmake
@@ -122,7 +122,7 @@ macro(create_pyside_module)
     get_target_property(qt_core_includes Qt${QT_MAJOR_VERSION}::Core
                         INTERFACE_INCLUDE_DIRECTORIES)
     set(shiboken_include_dir_list ${pyside6_SOURCE_DIR} ${qt_platform_includes}
-        ${qt_core_includes})
+        ${qt_core_includes} ${OPENGL_INCLUDE_DIRS})
     if(module_ADDITIONAL_INCLUDE_DIRS)
         list(APPEND shiboken_include_dir_list ${${module_ADDITIONAL_INCLUDE_DIRS}})
     endif()
@@ -308,6 +308,7 @@ macro(create_pyside_module)
     list(APPEND ld_prefix_list "${pysidebindings_BINARY_DIR}/libpysideqml")
     list(APPEND ld_prefix_list "${pysidebindings_BINARY_DIR}/libpysideremoteobjects")
     list(APPEND ld_prefix_list "${SHIBOKEN_SHARED_LIBRARY_DIR}")
+    list(APPEND ld_prefix_list "${pysidebindings_BINARY_DIR}/../shiboken6/libshiboken")
     if(WIN32)
         list(APPEND ld_prefix_list "${QT6_INSTALL_PREFIX}/${QT6_INSTALL_BINS}")
     endif()
@@ -349,6 +350,7 @@ macro(create_pyside_module)
         set(SHIBOKEN_PYTHON_MODULE_DIR "${PYTHON_SITE_PACKAGES}/shiboken6")
         set(generate_pyi_options ${module_NAME} --sys-path
             "${pysidebindings_BINARY_DIR}"
+            "${pysidebindings_BINARY_DIR}/.."
             "${SHIBOKEN_PYTHON_MODULE_DIR}/.."
             "${SHIBOKEN_PYTHON_MODULE_DIR}/../../..")     # use the layer above shiboken6
         if (QUIET_BUILD)

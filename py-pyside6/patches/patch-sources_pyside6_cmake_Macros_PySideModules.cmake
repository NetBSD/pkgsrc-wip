$NetBSD$

- Add OpenGL include directories.
- Fix shiboken6 module directory.

--- sources/pyside6/cmake/Macros/PySideModules.cmake.orig	2025-01-27 08:28:26.000000000 +0000
+++ sources/pyside6/cmake/Macros/PySideModules.cmake
@@ -121,8 +121,9 @@ macro(create_pyside_module)
     # Add QtCore since include conventions are sometimes violated for its classes
     get_target_property(qt_core_includes Qt${QT_MAJOR_VERSION}::Core
                         INTERFACE_INCLUDE_DIRECTORIES)
+    find_package(OpenGL COMPONENTS OpenGL)
     set(shiboken_include_dir_list ${pyside6_SOURCE_DIR} ${qt_platform_includes}
-        ${qt_core_includes})
+        ${qt_core_includes} ${OPENGL_INCLUDE_DIRS})
     if(module_ADDITIONAL_INCLUDE_DIRS)
         list(APPEND shiboken_include_dir_list ${${module_ADDITIONAL_INCLUDE_DIRS}})
     endif()
@@ -338,7 +339,7 @@ macro(create_pyside_module)
     if(NOT (PYSIDE_IS_CROSS_BUILD OR DISABLE_PYI))
         set(generate_pyi_options ${module_NAME} --sys-path
             "${pysidebindings_BINARY_DIR}"
-            "${SHIBOKEN_PYTHON_MODULE_DIR}/..")     # use the layer above shiboken6
+            "${SHIBOKEN_PYTHON_MODULE_DIR}/../..")     # use the layer above shiboken6
         if (QUIET_BUILD)
             list(APPEND generate_pyi_options "--quiet")
         endif()

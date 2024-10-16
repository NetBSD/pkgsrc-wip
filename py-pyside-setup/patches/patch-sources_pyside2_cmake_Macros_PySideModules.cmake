$NetBSD$

Make shiboken look in .buildlink for headers.

--- sources/pyside2/cmake/Macros/PySideModules.cmake.orig	2024-08-28 09:49:26.000000000 +0000
+++ sources/pyside2/cmake/Macros/PySideModules.cmake
@@ -94,7 +94,9 @@ macro(create_pyside_module)
     # Workaround: Added ${QT_INCLUDE_DIR}/QtCore until
     # qtdeclarative/8d560d1bf0a747bf62f73fad6b6774095442d9d2 has reached qt5.git
     string(REPLACE ";" ${PATH_SEP} core_includes "${Qt5Core_INCLUDE_DIRS}")
-    set(shiboken_include_dirs ${pyside2_SOURCE_DIR}${PATH_SEP}${QT_INCLUDE_DIR}${PATH_SEP}${core_includes})
+    set(buildlink_include_dir "${pyside2_SOURCE_DIR}/../../../../.buildlink/include")
+    set(buildlink_qt_include_dir "${pyside2_SOURCE_DIR}/../../../../.buildlink/qt5/include")
+    set(shiboken_include_dirs ${pyside2_SOURCE_DIR}${PATH_SEP}${buildlink_include_dir}${PATH_SEP}${buildlink_qt_include_dir}${PATH_SEP}${core_includes})
     set(shiboken_framework_include_dirs_option "")
     if(CMAKE_HOST_APPLE)
         set(shiboken_framework_include_dirs "${QT_FRAMEWORK_INCLUDE_DIR}")

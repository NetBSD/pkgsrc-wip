$NetBSD$

* only install non-generated files, this is needed since use in source build

--- cmake/QtBaseGlobalTargets.cmake.orig	2021-10-10 21:32:13.849657000 +0000
+++ cmake/QtBaseGlobalTargets.cmake
@@ -267,6 +267,8 @@ qt_copy_or_install(FILES
 qt_copy_or_install(DIRECTORY
     "config.tests/static_link_order"
     DESTINATION "${__GlobalConfig_install_dir}/config.tests"
+    FILES_MATCHING PATTERN "*.cpp"
+    PATTERN "CMakeLists.txt"
 )
 
 # Install public CMake files.

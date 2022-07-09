$NetBSD$

* only install non-generated files, this is needed since use in source build

--- cmake/QtBaseGlobalTargets.cmake.orig	2022-05-25 08:58:52.000000000 +0000
+++ cmake/QtBaseGlobalTargets.cmake
@@ -294,6 +294,8 @@ qt_copy_or_install(DIRECTORY
     "config.tests/static_link_order"
     "config.tests/binary_for_strip"
     DESTINATION "${__GlobalConfig_install_dir}/config.tests"
+    FILES_MATCHING PATTERN "*.cpp"
+    PATTERN "CMakeLists.txt"
 )
 
 # Install qt-internal-strip and qt-internal-ninja files.

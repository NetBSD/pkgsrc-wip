$NetBSD$

* make sure the assimp options turn it on and off
* fix typo to enable pkgsrc assimp

--- src/plugins/sceneparsers/configure.cmake.orig	2021-01-28 05:17:13.000000000 +0000
+++ src/plugins/sceneparsers/configure.cmake
@@ -25,11 +25,13 @@ qt_config_compile_test("qt3d_assimp"
 
 qt_feature("qt3d_assimp" PUBLIC PRIVATE
     LABEL "Assimp"
+    ENABLE INPUT_assimp STREQUAL 'system' OR INPUT_assimp STREQUAL 'qt'
+    DISABLE INPUT_assimp STREQUAL 'no' 
 )
 qt_feature_definition("qt3d_assimp" "QT_NO_ASSIMP" NEGATE VALUE "1")
 qt_feature("qt3d_system_assimp" PRIVATE
     LABEL "System Assimp"
-    CONDITION QT_FEATURE_qt3d_assimp AND TEST_assimp
+    CONDITION QT_FEATURE_qt3d_assimp AND TEST_qt3d_assimp
     ENABLE INPUT_assimp STREQUAL 'system'
     DISABLE INPUT_assimp STREQUAL 'qt'
 )

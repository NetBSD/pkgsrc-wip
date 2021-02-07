$NetBSD$

* enable mng

--- src/imageformats/configure.cmake.orig	2021-01-28 05:17:06.000000000 +0000
+++ src/imageformats/configure.cmake
@@ -17,7 +17,7 @@ set_property(CACHE INPUT_webp PROPERTY S
 qt_find_package(WrapJasper PROVIDED_TARGETS WrapJasper::WrapJasper MODULE_NAME imageformats QMAKE_LIB jasper)
 qt_find_package(TIFF PROVIDED_TARGETS TIFF::TIFF MODULE_NAME imageformats QMAKE_LIB tiff)
 qt_find_package(WrapWebP PROVIDED_TARGETS WrapWebP::WrapWebP MODULE_NAME imageformats QMAKE_LIB webp)
-
+qt_find_package(WrapMNG PROVIDED_TARGETS PkgConfig::MNG MODULE_NAME imageformats QMAKE_LIB mng)
 
 #### Tests
 
@@ -33,7 +33,7 @@ qt_feature("jasper" PRIVATE
 qt_feature_definition("jasper" "QT_NO_IMAGEFORMAT_JASPER" NEGATE)
 qt_feature("mng" PRIVATE
     LABEL "MNG"
-    CONDITION libs.mng OR FIXME
+    CONDITION TARGET PkgConfig::MNG
     DISABLE INPUT_mng STREQUAL 'no'
 )
 qt_feature("tiff" PRIVATE

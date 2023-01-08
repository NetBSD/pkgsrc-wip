$NetBSD$

We don't want a specific binary only for Darwin.

--- avidemux/qt4/adm_osx.cmake.orig	2022-09-17 13:59:17.000000000 +0000
+++ avidemux/qt4/adm_osx.cmake
@@ -30,7 +30,6 @@ MACRO(ADM_MAIN_APP)
     ELSE(CREATE_BUNDLE)
         ADD_EXECUTABLE(avidemux3_${QT_EXTENSION} ${ADM_EXE_SRCS})
     ENDIF(CREATE_BUNDLE)
-    SET_PROPERTY(TARGET avidemux3_${QT_EXTENSION} PROPERTY OUTPUT_NAME Avidemux${AVIDEMUX_MAJOR_MINOR})
     IF (${QT_EXTENSION} STREQUAL "qt6")
         TARGET_LINK_LIBRARIES(avidemux3_${QT_EXTENSION} "${QT_CORE_LIBRARY}" "${QT_QTGUI_LIBRARY}")
     ELSE (${QT_EXTENSION} STREQUAL "qt6")

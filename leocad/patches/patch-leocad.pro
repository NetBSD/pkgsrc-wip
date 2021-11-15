$NetBSD$

Disable PCH.

--- leocad.pro.orig	2021-06-05 23:41:42.000000000 +0000
+++ leocad.pro
@@ -40,7 +40,6 @@ win32-msvc* {
 	QMAKE_LFLAGS += /INCREMENTAL
 	LIBS += -ladvapi32 -lshell32 -lopengl32 -luser32
 } else {
-	PRECOMPILED_HEADER = common/lc_global.h
 	LIBS += -lz
 	QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
 }

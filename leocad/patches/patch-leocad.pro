$NetBSD$

Disable PCH.

--- leocad.pro.orig	2025-09-02 07:47:24.896568456 +0000
+++ leocad.pro
@@ -47,7 +47,6 @@ win32-msvc* {
 	QMAKE_LFLAGS += /INCREMENTAL
 	LIBS += -ladvapi32 -lshell32 -lopengl32 -luser32
 } else {
-	PRECOMPILED_HEADER = common/lc_global.h
 	LIBS += -lz
 	QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
 }

$NetBSD$

Disable PCH.

--- leocad.pro.orig	2026-09-19 23:44:29.000000000 +0000
+++ leocad.pro
@@ -48,7 +48,7 @@ win32-msvc* {
 	LIBS += -ladvapi32 -lshell32 -lopengl32 -luser32
 	QMAKE_CXXFLAGS += /we4834
 } else {
-	PRECOMPILED_HEADER = common/lc_global.h
+	# PRECOMPILED_HEADER = common/lc_global.h
 	LIBS += -lz
 	QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
 	QMAKE_CXXFLAGS += -Werror=unused-result

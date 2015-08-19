$NetBSD: patch-src_install.cmake,v 1.1 2015/08/19 21:21:53 yhardy Exp $

Install binary to "bin" directory instead of "games".

--- src/install.cmake.orig	2015-08-12 11:53:24.000000000 +0000
+++ src/install.cmake
@@ -14,7 +14,7 @@ SET(SHAREDIR share CACHE PATH "System sh
 #SET(GAMES_SHAREDIR "${SHAREDIR}" CACHE PATH "Game data root dir")
 SET(GAMES_SHAREDIR "share/games/" CACHE PATH "Game data root dir")
 SET(DATADIR "${GAMES_SHAREDIR}/commandergenius")
-SET(APPDIR games CACHE PATH "Binary destination")
+SET(APPDIR bin CACHE PATH "Binary destination")
 SET(DOCDIR ${DATADIR} CACHE PATH "Docs destination")
 ENDIF(WIN32)
 

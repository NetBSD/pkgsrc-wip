$NetBSD: patch-src_install.cmake,v 1.1 2015/08/19 21:21:53 yhardy Exp $

Install binary to "bin" directory instead of "games".

--- src/install.cmake.orig	2017-10-18 19:06:51.000000000 +0000
+++ src/install.cmake
@@ -10,7 +10,7 @@ ELSE(WIN32)
 SET(SHAREDIR "/usr/share" CACHE PATH "System share dir location")
 SET(GAMES_SHAREDIR "${SHAREDIR}/games/" CACHE PATH "Game data root dir")
 SET(DATADIR "${GAMES_SHAREDIR}/commandergenius")
-SET(APPDIR games CACHE PATH "Binary destination")
+SET(APPDIR bin CACHE PATH "Binary destination")
 SET(DOCDIR ${DATADIR} CACHE PATH "Docs destination")
 SET(ICONDIR "${SHAREDIR}/icons/hicolor" CACHE PATH "Standard icon installation dir")
 SET(DESKTOPFILESDIR "${SHAREDIR}/applications" CACHE PATH "Application installation dir")

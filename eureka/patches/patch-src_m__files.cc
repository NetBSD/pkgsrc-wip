$NetBSD$

--- src/m_files.cc.orig	2019-08-30 15:58:23.000000000 +0000
+++ src/m_files.cc
@@ -721,6 +721,7 @@ static const char * SearchForIWAD(const 
 		"c:/doom2",
 		"c:/doom95",
 #else
+		"PKGSRC_DOOMWADDIR",
 		"/usr/share/games/doom",
 		"/usr/share/doom",
 		"/usr/local/share/games/doom",

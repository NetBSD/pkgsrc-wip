$NetBSD$

Add placeholder for pkgsrc DOOMWADDIR to beginning of search list.

--- src/m_files.cc.orig	2018-06-23 11:29:07.000000000 +0000
+++ src/m_files.cc
@@ -723,6 +723,7 @@ static const char * SearchForIWAD(const 
 		"c:/doom2",
 		"c:/doom95",
 #else
+		"PKGSRC_DOOMWADDIR",
 		"/usr/share/games/doom",
 		"/usr/share/doom",
 		"/usr/local/share/games/doom",

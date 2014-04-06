$NetBSD: patch-libfsemu_src_filesys.c,v 1.2 2014/04/06 13:33:55 rhialto Exp $

Add support for NetBSD.

--- libfsemu/src/filesys.c.orig	2014-03-25 19:40:58.000000000 +0000
+++ libfsemu/src/filesys.c
@@ -128,7 +128,7 @@ static void file_time_to_time_val(FILETI
 
 #if defined(WINDOWS)
 
-#elif defined(MACOSX)
+#elif defined(MACOSX) || defined(NETBSD)
 #define HAVE_STAT_TV_NSEC2
 #else
 #define HAVE_STAT_TV_NSEC

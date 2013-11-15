$NetBSD: patch-libfsemu_src_filesys.c,v 1.1 2013/11/15 12:26:23 rhialto Exp $

Add support for NetBSD.

--- libfsemu/src/filesys.c.orig	2013-10-23 17:57:59.000000000 +0000
+++ libfsemu/src/filesys.c
@@ -126,7 +126,7 @@ static void file_time_to_time_val(FILETI
 
 #if defined(WINDOWS)
 
-#elif defined(MACOSX)
+#elif defined(MACOSX) || defined(NETBSD)
 #define HAVE_STAT_TV_NSEC2
 #else
 #define HAVE_STAT_TV_NSEC

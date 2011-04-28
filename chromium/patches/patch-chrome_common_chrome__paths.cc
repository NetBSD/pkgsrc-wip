$NetBSD: patch-chrome_common_chrome__paths.cc,v 1.1 2011/04/28 03:09:02 rxg Exp $

--- chrome/common/chrome_paths.cc.orig	2011-04-13 08:01:58.000000000 +0000
+++ chrome/common/chrome_paths.cc
@@ -164,7 +164,7 @@ bool PathProvider(int key, FilePath* res
       cur = cur.Append(FILE_PATH_LITERAL("inspector"));
       break;
     case chrome::DIR_APP_DICTIONARIES:
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_POSIX)
       // We can't write into the EXE dir on Linux, so keep dictionaries
       // alongside the safe browsing database in the user data dir.
       // And we don't want to write into the bundle on the Mac, so push

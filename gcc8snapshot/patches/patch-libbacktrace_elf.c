$NetBSD$

--- libbacktrace/elf.c.orig	2017-10-05 16:39:38.000000000 +0000
+++ libbacktrace/elf.c
@@ -733,7 +733,7 @@ elf_syminfo (struct backtrace_state *sta
 static int
 elf_is_symlink (const char *filename)
 {
-  struct stat st;
+  struct stat st = {0};
 
   if (lstat (filename, &st) < 0)
     return 0;

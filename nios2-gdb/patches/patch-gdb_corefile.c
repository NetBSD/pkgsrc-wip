$NetBSD: patch-gdb_corefile.c,v 1.1 2013/11/17 01:03:27 makoto Exp $

workaround to avoid segmentation fault at getenv

--- gdb/corefile.c~	2013-06-26 06:02:27.000000000 +0900
+++ gdb/corefile.c	2013-11-17 09:53:25.000000000 +0900
@@ -457,7 +457,7 @@ Use `set gnutarget auto' to specify auto
 				   show_gnutarget_string,
 				   &setlist, &showlist);
 
-  if (getenv ("GNUTARGET"))
+  if (0 && getenv ("GNUTARGET"))
     set_gnutarget (getenv ("GNUTARGET"));
   else
     set_gnutarget ("auto");

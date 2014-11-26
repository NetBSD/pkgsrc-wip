$NetBSD: patch-src_mp3fs.c,v 1.1 2014/11/26 22:29:32 thomasklausner Exp $

--- src/mp3fs.c.orig	2014-05-14 19:48:45.000000000 +0000
+++ src/mp3fs.c
@@ -138,7 +138,7 @@ static int mp3fs_opt_proc(void* data, co
             exit(0);
     }
 
-    return 1;
+    return 0;
 }
 
 int main(int argc, char *argv[]) {

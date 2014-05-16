$NetBSD: patch-in.ctcs_in.ctcs.c,v 1.1 2014/05/16 15:19:19 hfath Exp $

--- in.ctcs/in.ctcs.c.orig	2011-01-13 15:53:55.000000000 +0000
+++ in.ctcs/in.ctcs.c
@@ -204,7 +204,7 @@ char* strip_term(char* str) {
 // Clears the input file
 void blank_input_file() {
     FILE* f = fopen(infilename, "w");
-    flock(f, LOCK_EX);
+    flock(fileno(f), LOCK_EX);
     fclose(f);
 }
 
@@ -230,7 +230,7 @@ void update_file() {
 
     lastfile = time(NULL);
     FILE* f = fopen(filename, "w");
-    flock(f, LOCK_EX);
+    flock(fileno(f), LOCK_EX);
     fprintf(f, "torrent %s\n", torrentfile);
     fprintf(f, "peerid %s\n", peerid);
     fprintf(f, "lastmessage %s\n", lastmessage);

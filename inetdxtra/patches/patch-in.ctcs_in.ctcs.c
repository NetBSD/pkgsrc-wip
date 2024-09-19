$NetBSD$

An ANSI C FILE and a unix file number are two kettle of fish. Convert.

--- in.ctcs/in.ctcs.c.orig	2013-04-26 20:00:11.000000000 +0000
+++ in.ctcs/in.ctcs.c
@@ -25,6 +25,7 @@
 */
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <string.h>
 #include <time.h>
 #include <fcntl.h>
@@ -157,7 +158,8 @@ int get_unused_bandwidth() {
             // Is this our file? Ignore if it is
             if (!strstr(ds->d_name, ourpid)) {
                 // Ok, open the file and find the dlrate line
-                sprintf(fname, "%s/%s", WORKING_FOLDER, ds->d_name);
+		    snprintf(fname, sizeof fname, "%s/%s",
+			WORKING_FOLDER, ds->d_name);
                 f = fopen(fname, "r");
                 while (!feof(f)) {
                     fgets(line, sizeof(line), f);
@@ -204,7 +206,7 @@ char* strip_term(char* str) {
 // Clears the input file
 void blank_input_file() {
     FILE* f = fopen(infilename, "w");
-    flock(f, LOCK_EX);
+    flock(fileno(f), LOCK_EX);
     fclose(f);
 }
 
@@ -230,7 +232,7 @@ void update_file() {
 
     lastfile = time(NULL);
     FILE* f = fopen(filename, "w");
-    flock(f, LOCK_EX);
+    flock(fileno(f), LOCK_EX);
     fprintf(f, "torrent %s\n", torrentfile);
     fprintf(f, "peerid %s\n", peerid);
     fprintf(f, "lastmessage %s\n", lastmessage);

$NetBSD$

Add missing #include
Rename local gethostname() to avoid collision

--- in.smtp/in.smtp.c.orig	2013-04-26 20:00:10.000000000 +0000
+++ in.smtp/in.smtp.c
@@ -28,6 +28,7 @@
 */
 #include <stdio.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <string.h>
 #include <time.h>
 
@@ -176,7 +177,7 @@ int parse_address(char* dest) {
 }
 
 // Returns the machine's hostname
-char* gethostname() {
+char* sm_gethostname() {
     return get_command_output(hostname, "hostname");
 }
 
@@ -201,7 +202,7 @@ int main(int argc, char** argv) {
     sprintf(dataname, DATA_FILE, getpid());
 
     // Send our greeting first
-    printf("220 %s SMTP in.smtp (%s)\n", gethostname(), getostype());
+    printf("220 %s SMTP in.smtp (%s)\n", sm_gethostname(), getostype());
     fflush(stdout);
 
     // SMTP is a 3 stage protocol, the phase tells us where we're
@@ -226,7 +227,8 @@ int main(int argc, char** argv) {
                 printf("250 Hello %s\n", helo);
                 fflush(stdout);
                 // Pre-generate our received header
-                sprintf(recheader, "Received: from %s by %s ; %s\r\n", helo, gethostname(), get_date_time());
+                sprintf(recheader, "Received: from %s by %s ; %s\r\n",
+		    helo, sm_gethostname(), get_date_time());
                 phase++;
             }
 

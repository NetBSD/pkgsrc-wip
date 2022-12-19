$NetBSD$

Prevent unsafe use of tmpnam(). 

--- mgdiff.c.orig	1994-09-29 01:56:53.000000000 +0000
+++ mgdiff.c
@@ -1110,7 +1110,9 @@ int main (int argc, char *argv[])
 	 */
     case 3:
 	if (strcmp (argv[1], "-") == 0) {
-	    tempfname = tempnam (NULL, "mgdif");
+	    char xxx[20];
+	    sprintf(tempfname, "mgdif.XXXXXXXX");
+	    close(mkstemp (tempfname));
 	    str_fnamel = strdup (tempfname);
 	    str_snamel = strdup (user_filename);
 	    if (!copy_to_file (stdin, tempfname)) {
@@ -1131,7 +1133,9 @@ int main (int argc, char *argv[])
 	}
 
 	if (strcmp (argv[2], "-") == 0) {
-	    tempfname = tempnam (NULL, "mgdif");
+	   char xxx[20];
+            sprintf(tempfname, "mgdif.XXXXXXXX");
+            close(mkstemp (tempfname));
 	    str_fnamer = strdup (tempfname);
 	    str_snamer = strdup (user_filename);
 	    if (!copy_to_file (stdin, tempfname)) {

$NetBSD$

--- sources/lib/run-time/debug-print.c.orig	2015-09-25 09:55:53.000000000 +0000
+++ sources/lib/run-time/debug-print.c
@@ -464,7 +464,7 @@ void dylan_format (STREAM stream, dylan_
   for (i = 0; i < size; i++) {
     char c = string[i];
     if (percent_p) {
-      char cc = (char)toupper(c);
+      char cc = (char)toupper((unsigned char)c);
       switch (cc) {
         case 'S': case 'C':
           if (argument_index < argument_count) {
@@ -510,4 +510,3 @@ void dylan_print_object (dylan_value obj
   fputs("\n", stdout);
   fflush(stdout);
 }
-

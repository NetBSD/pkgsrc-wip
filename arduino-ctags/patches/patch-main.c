$NetBSD$

--- main.c.orig	2019-03-25 18:42:04.921900823 +0000
+++ main.c
@@ -522,7 +522,7 @@ static void makeTags (cookedArgs *args)
  *		Start up code
  */
 
-extern int main (int __unused__ argc, char **argv)
+extern int main (int CTAGS_UNUSED argc, char **argv)
 {
 	cookedArgs *args;
 #ifdef VMS

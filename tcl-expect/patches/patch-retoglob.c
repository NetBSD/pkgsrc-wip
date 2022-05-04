$NetBSD$

#       retoglob.c
#       SVR5 name space clash

# emailed Upstream Swtempber 2019

--- retoglob.c.orig	2018-02-02 19:15:52.000000000 +0000
+++ retoglob.c	2019-08-26 05:28:32.206672005 +0000
@@ -10,8 +10,8 @@
 static void
 ExpChopNested _ANSI_ARGS_ ((Tcl_UniChar** xstr,
 			    int*          xstrlen,
-			    Tcl_UniChar   open,
-			    Tcl_UniChar   close));
+			    Tcl_UniChar   openp,
+			    Tcl_UniChar   closep));
 
 static Tcl_UniChar*
 ExpLiteral _ANSI_ARGS_ ((Tcl_UniChar* nexto,
@@ -513,14 +513,14 @@ static void
 #ifdef _AIX
 ExpChopNested (Tcl_UniChar** xstr,
 	       int*          xstrlen,
-	       Tcl_UniChar   open,
-	       Tcl_UniChar   close)
+	       Tcl_UniChar   openp,
+	       Tcl_UniChar   closep)
 #else
-ExpChopNested (xstr,xstrlen, open, close)
+ExpChopNested (xstr,xstrlen, openp, closep)
      Tcl_UniChar** xstr;
      int*          xstrlen;
-     Tcl_UniChar   open;
-     Tcl_UniChar   close;
+     Tcl_UniChar   openp;
+     Tcl_UniChar   closep;
 #endif
 {
   Tcl_UniChar* str    = *xstr;
@@ -528,9 +528,9 @@ ExpChopNested (xstr,xstrlen, open, close
   int          level = 0;
 
   while (strlen) {
-    if (MATCHC (open)) {
+    if (MATCHC (openp)) {
       level ++;
-    } else if (MATCHC (close)) {
+    } else if (MATCHC (closep)) {
       level --;
       if (level < 0) {
 	CHOP (1);

$NetBSD$

--- main/flite_time_main.c.orig	2009-04-08 13:18:42.000000000 +0000
+++ main/flite_time_main.c
@@ -112,7 +112,7 @@ static const char *time_approx(int hour,
 
     mm = minute % 5;
 
-    if ((mm == 0) || (mm == 4))
+    if (mm == 0)
 	return "exactly";
     else if (mm == 1)
 	return "just after";

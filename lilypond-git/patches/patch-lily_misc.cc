$NetBSD: patch-lily_misc.cc,v 1.1 2014/04/06 14:17:45 thomasklausner Exp $

Fix namespace issue with clang.

--- lily/misc.cc.orig	2014-04-06 12:44:15.000000000 +0000
+++ lily/misc.cc
@@ -31,7 +31,7 @@ int
 intlog2 (int d)
 {
   if (d <= 0)
-    error ("intlog2 with negative argument: " + to_string (d));
+    error ("intlog2 with negative argument: " + ::to_string (d));
   int i = 0;
   while ((d != 1))
     {

$NetBSD: patch-lily_page-turn-page-breaking.cc,v 1.1 2013/11/13 07:26:34 thomasklausner Exp $

--- lily/page-turn-page-breaking.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/page-turn-page-breaking.cc
@@ -232,7 +232,7 @@ Page_turn_page_breaking::solve ()
   for (vsize i = 0; i < last_break_position (); i++)
     {
       calc_subproblem (i);
-      progress_indication (string ("[") + to_string (i + 1) + "]");
+      progress_indication (string ("[") + ::to_string (i + 1) + "]");
     }
   progress_indication ("\n");
 

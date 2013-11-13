$NetBSD: patch-lily_arpeggio.cc,v 1.1 2013/11/13 07:26:34 thomasklausner Exp $

--- lily/arpeggio.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/arpeggio.cc
@@ -163,7 +163,7 @@ Arpeggio::print (SCM smob)
   if (dir)
     {
       Font_metric *fm = Font_interface::get_default_font (me);
-      arrow = fm->find_by_name ("scripts.arpeggio.arrow." + to_string (dir));
+      arrow = fm->find_by_name ("scripts.arpeggio.arrow." + ::to_string (dir));
       heads[dir] -= dir * arrow.extent (Y_AXIS).length ();
     }
 

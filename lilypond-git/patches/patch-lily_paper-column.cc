$NetBSD: patch-lily_paper-column.cc,v 1.1 2013/11/13 07:26:34 thomasklausner Exp $

--- lily/paper-column.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/paper-column.cc
@@ -237,7 +237,7 @@ Paper_column::print (SCM p)
 {
   Paper_column *me = dynamic_cast<Paper_column *> (unsmob_grob (p));
 
-  string r = to_string (Paper_column::get_rank (me));
+  string r = ::to_string (Paper_column::get_rank (me));
 
   Moment *mom = unsmob_moment (me->get_property ("when"));
   string when = mom ? mom->to_string () : "?/?";

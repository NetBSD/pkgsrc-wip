$NetBSD: patch-lily_paper-column-engraver.cc,v 1.1 2013/11/13 07:26:34 thomasklausner Exp $

--- lily/paper-column-engraver.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/paper-column-engraver.cc
@@ -50,7 +50,7 @@ void
 Paper_column_engraver::finalize ()
 {
   if (! (breaks_ % 8))
-    progress_indication ("[" + to_string (breaks_) + "]");
+    progress_indication ("[" + ::to_string (breaks_) + "]");
 
   if (!made_columns_)
     {
@@ -269,7 +269,7 @@ Paper_column_engraver::stop_translation_
       breaks_++;
 
       if (! (breaks_ % 8))
-        progress_indication ("[" + to_string (breaks_) + "]");
+        progress_indication ("[" + ::to_string (breaks_) + "]");
     }
 
   context ()->get_score_context ()->unset_property (ly_symbol2scm ("forbidBreak"));

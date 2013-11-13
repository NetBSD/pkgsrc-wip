$NetBSD: patch-lily_input.cc,v 1.1 2013/11/13 07:26:34 thomasklausner Exp $

--- lily/input.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/input.cc
@@ -142,7 +142,7 @@ string
 Input::line_number_string () const
 {
   if (source_file_)
-    return to_string (source_file_->get_line (start_));
+    return ::to_string (source_file_->get_line (start_));
   return "?";
 }
 

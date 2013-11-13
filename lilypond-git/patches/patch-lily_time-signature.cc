$NetBSD: patch-lily_time-signature.cc,v 1.1 2013/11/13 07:26:35 thomasklausner Exp $

--- lily/time-signature.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/time-signature.cc
@@ -67,7 +67,7 @@ Time_signature::special_time_signature (
     return numbered_time_signature (me, n, d);
 
   if ((style == "default") || (style == ""))
-    style = to_string ("C");
+    style = ::to_string ("C");
 
   if (style == "C")
     {
@@ -77,7 +77,7 @@ Time_signature::special_time_signature (
         return numbered_time_signature (me, n, d);
     }
 
-  string char_name = style + to_string (n) + to_string (d);
+  string char_name = style + ::to_string (n) + ::to_string (d);
   me->set_property ("font-encoding", ly_symbol2scm ("fetaMusic"));
   Stencil out = Font_interface::get_default_font (me)
                 ->find_by_name ("timesig." + char_name);
@@ -100,9 +100,9 @@ Time_signature::numbered_time_signature 
                     chain);
 
   SCM sn = Text_interface::interpret_markup (me->layout ()->self_scm (), chain,
-                                             ly_string2scm (to_string (num)));
+                                             ly_string2scm (::to_string (num)));
   SCM sd = Text_interface::interpret_markup (me->layout ()->self_scm (), chain,
-                                             ly_string2scm (to_string (den)));
+                                             ly_string2scm (::to_string (den)));
 
   Stencil n = *unsmob_stencil (sn);
   Stencil d = *unsmob_stencil (sd);

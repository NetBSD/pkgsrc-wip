$NetBSD: patch-lily_flag.cc,v 1.1 2013/11/13 07:26:34 thomasklausner Exp $

--- lily/flag.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/flag.cc
@@ -105,7 +106,7 @@ Flag::glyph_name (SCM smob)
 
   char dir = (d == UP) ? 'u' : 'd';
   string font_char = flag_style
-                     + to_string (dir) + staffline_offs + to_string (log);
+                     + ::to_string (dir) + staffline_offs + ::to_string (log);
   return ly_string2scm ("flags." + font_char);
 }
 
@@ -143,11 +144,11 @@ Flag::print (SCM smob)
       string stroke_style = ly_scm2string (stroke_style_scm);
       if (!stroke_style.empty ())
         {
-          string font_char = flag_style + to_string (dir) + stroke_style;
+          string font_char = flag_style + ::to_string (dir) + stroke_style;
           Stencil stroke = fm->find_by_name ("flags." + font_char);
           if (stroke.is_empty ())
             {
-              font_char = to_string (dir) + stroke_style;
+              font_char = ::to_string (dir) + stroke_style;
               stroke = fm->find_by_name ("flags." + font_char);
             }
           if (stroke.is_empty ())

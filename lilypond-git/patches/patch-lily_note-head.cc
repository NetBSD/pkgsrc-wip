$NetBSD: patch-lily_note-head.cc,v 1.1 2013/11/13 07:26:34 thomasklausner Exp $

--- lily/note-head.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/note-head.cc
@@ -38,7 +38,7 @@ internal_print (Grob *me, string *font_c
 {
   string style = robust_symbol2string (me->get_property ("style"), "default");
 
-  string suffix = to_string (min (robust_scm2int (me->get_property ("duration-log"), 2), 2));
+  string suffix = ::to_string (min (robust_scm2int (me->get_property ("duration-log"), 2), 2));
   if (style != "default")
     suffix = robust_scm2string (me->get_property ("glyph-name"), "");
 

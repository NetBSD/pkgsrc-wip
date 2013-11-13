$NetBSD: patch-lily_system-start-delimiter.cc,v 1.1 2013/11/13 07:26:35 thomasklausner Exp $

--- lily/system-start-delimiter.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/system-start-delimiter.cc
@@ -169,7 +169,7 @@ System_start_delimiter::staff_brace (Gro
     }
   while (hi - lo > 1);
 
-  Stencil stil (fm->find_by_name ("brace" + to_string (lo)));
+  Stencil stil (fm->find_by_name ("brace" + ::to_string (lo)));
   stil.translate_axis (-b[X_AXIS].length () / 2, X_AXIS);
 
   stil.translate_axis (-0.2, X_AXIS);

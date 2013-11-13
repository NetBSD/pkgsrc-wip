$NetBSD: patch-lily_system.cc,v 1.1 2013/11/13 07:26:35 thomasklausner Exp $

--- lily/system.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/system.cc
@@ -223,7 +224,7 @@ System::get_paper_systems ()
       scm_vector_set_x (lines, scm_from_int (i),
                         system->get_paper_system ());
 
-      debug_output (to_string (i) + "]", false);
+      debug_output (::to_string (i) + "]", false);
     }
   return lines;
 }

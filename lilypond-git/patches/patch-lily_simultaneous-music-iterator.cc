$NetBSD: patch-lily_simultaneous-music-iterator.cc,v 1.1 2013/11/13 07:26:35 thomasklausner Exp $

--- lily/simultaneous-music-iterator.cc.orig	2013-11-12 11:12:50.000000000 +0000
+++ lily/simultaneous-music-iterator.cc
@@ -63,7 +64,7 @@ Simultaneous_music_iterator::construct_c
 
       SCM name = ly_symbol2scm (get_outlet ()->context_name ().c_str ());
       Context *c = (j && create_separate_contexts_)
-                   ? get_outlet ()->find_create_context (name, to_string (j), SCM_EOL)
+                   ? get_outlet ()->find_create_context (name, ::to_string (j), SCM_EOL)
                    : get_outlet ();
 
       if (!c)

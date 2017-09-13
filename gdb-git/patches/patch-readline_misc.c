$NetBSD$

--- readline/misc.c.orig	2017-09-11 11:24:05.000000000 +0000
+++ readline/misc.c
@@ -453,7 +453,7 @@ _rl_revert_all_lines ()
   entry = (hpos == history_length) ? previous_history () : current_history ();
   while (entry)
     {
-      if (ul = (UNDO_LIST *)entry->data)
+      if ((ul = (UNDO_LIST *)entry->data))
 	{
 	  if (ul == saved_undo_list)
 	    saved_undo_list = 0;

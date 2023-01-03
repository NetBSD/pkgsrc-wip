$NetBSD$

--- dtools/xtmEditEntry.c.orig	1997-05-04 22:27:52.000000000 +0000
+++ dtools/xtmEditEntry.c
@@ -877,7 +877,7 @@ static Widget 
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) helpCB, (XtPointer) index );
+                   (XtCallbackProc) helpCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -2915,7 +2915,7 @@ static void 
   /* Code. */
 
   xtmHlDisplayHelp( editor_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     edit_window_id, "" );
 
   return;

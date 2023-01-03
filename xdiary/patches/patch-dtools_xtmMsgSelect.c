$NetBSD$

--- dtools/xtmMsgSelect.c.orig	1995-02-18 14:53:48.000000000 +0000
+++ dtools/xtmMsgSelect.c
@@ -438,7 +438,7 @@ static Widget 
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) infoCB, (XtPointer) index );
+                   (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -849,7 +849,7 @@ static void 
   /* Code. */
 
   xtmHlDisplayHelp( sel_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     select_window_id, "" );
 
   return;

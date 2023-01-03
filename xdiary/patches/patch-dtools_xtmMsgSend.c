$NetBSD$

--- dtools/xtmMsgSend.c.orig	1997-05-04 23:13:08.000000000 +0000
+++ dtools/xtmMsgSend.c
@@ -611,7 +611,7 @@ static Widget 
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) infoCB, (XtPointer) index );
+                   (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -939,7 +939,7 @@ static Widget 
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) infoCB, (XtPointer) index );
+                   (XtCallbackProc) infoCB, (XtPointer)(intptr_t)index );
   }
 
   /* We can't do context sensitive help. */
@@ -1811,7 +1811,7 @@ static void 
   /* Code. */
 
   xtmHlDisplayHelp( send_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     send_window_id, "" );
 
   return;

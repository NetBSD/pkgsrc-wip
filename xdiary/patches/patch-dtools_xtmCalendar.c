$NetBSD$

--- dtools/xtmCalendar.c.orig	1997-05-04 21:09:55.000000000 +0000
+++ dtools/xtmCalendar.c
@@ -779,7 +779,7 @@ static Widget
                                                    &help_casc[ index ] );
 
     XtAddCallback( menuHelpBu[ index ], XmNactivateCallback, 
-                   (XtCallbackProc) infoCB, (XtPointer) index );
+                   (XtCallbackProc) infoCB, (XtPointer)(intptr_t) index );
   }
 
   /* We can't do context sensitive help. */
@@ -1406,7 +1406,7 @@ static void 
   /* Code. */
 
   /* About window? */
-  if( (int) call_data -> data == 6 ) {
+  if( (intptr_t) call_data -> data == 6 ) {
     xtmHlDisplayAboutWindow( cal_ref -> calFormW );
 
     return;
@@ -1414,7 +1414,7 @@ static void 
 
   /* Use the standard help. */
   xtmHlDisplayHelp( cal_ref -> appl_data_ref -> info_handle,
-                    (int) call_data -> data,
+                    (intptr_t) call_data -> data,
                     cal_window_id, "" );
 
   return;
